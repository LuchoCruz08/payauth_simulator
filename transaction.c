#include <stdio.h>
#include <string.h>
#include "transaction.h"

int load_transactions(const char* filename, Transaction* transactions, int max_transactions) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open transactions file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%19s %5s %f %3s",
                  transactions[count].card_number,
                  transactions[count].expiry_date,
                  &transactions[count].amount,
                  transactions[count].currency) == 4) {
        count++;
        if (count >= max_transactions) break;
    }

    fclose(file);
    return count;
}
