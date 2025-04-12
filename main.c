#include <stdio.h>
#include "transaction.h"
#include "auth_engine.h"
#include "logger.h"

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int count = load_transactions("transactions.txt", transactions, MAX_TRANSACTIONS);
    if (count == 0) {
        printf("No transactions loaded.\n");
        return 1;
    }

    init_logger("transaction_log.txt");

    int i = 0;
    for (i; i < count; i++) {
        printf("\n--- Processing Transaction #%d ---\n", i + 1);
        AuthResult result = authorize_transaction(&transactions[i]);

        switch (result) {
            case AUTH_APPROVED: printf("APPROVED\n"); break;
            case AUTH_DECLINED: printf("DECLINED\n"); break;
            case AUTH_FLAGGED:  printf("FLAGGED\n"); break;
        }

        log_transaction(&transactions[i], result);
    }

    print_summary_report();
    close_logger();
    return 0;
}
