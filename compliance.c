#include <stdio.h>
#include <string.h>
#include "compliance.h"

int check_compliance(const Transaction* tx) {
    const float MAX_LIMIT = 10000.0f;
    if (tx->amount > MAX_LIMIT) {
        printf("Compliance rule: amount exceeds limit (%.2f)\n", MAX_LIMIT);
        return 0;
    }

    const char* accepted_currencies[] = {"USD", "EUR", "GBP"};
    int valid_currency = 0;
    int i = 0;
    for (i; i < 3; i++) {
        if (strcmp(tx->currency, accepted_currencies[i]) == 0) {
            valid_currency = 1;
            break;
        }
    }

    if (!valid_currency) {
        printf("Compliance rule: unsupported currency\n");
        return 0;
    }

    return 1;
}
