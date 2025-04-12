#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

static FILE* log_file = NULL;
static int approved_count = 0;
static int declined_count = 0;
static int flagged_count = 0;

void init_logger(const char* filename) {
    log_file = fopen(filename, "w");
    if (!log_file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
}

void log_transaction(const Transaction* tx, AuthResult result) {
    if (!log_file) return;

    const char* result_str = result == AUTH_APPROVED ? "APPROVED" :
                             result == AUTH_DECLINED ? "DECLINED" : "FLAGGED";

    fprintf(log_file, "Transaction: Card=%s | Amount=%.2f | Currency=%s | Result=%s\n",
            tx->card_number, tx->amount, tx->currency, result_str);

    switch (result) {
        case AUTH_APPROVED: approved_count++; break;
        case AUTH_DECLINED: declined_count++; break;
        case AUTH_FLAGGED:  flagged_count++;  break;
    }
}

void close_logger(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

void print_summary_report(void) {
    printf("\n================ SUMMARY REPORT ================\n");
    printf("Approved Transactions : %d\n", approved_count);
    printf("Declined Transactions : %d\n", declined_count);
    printf("Flagged Transactions  : %d\n", flagged_count);
    printf("================================================\n");
}
