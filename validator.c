#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validator.h"

static int luhn_check(const char* card) {
    int sum = 0, alt = 0, len = strlen(card);
    int i;
    for (i = len - 1; i >= 0; i--) {
        if (!isdigit(card[i])) return 0;
        int digit = card[i] - '0';
        if (alt) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alt = !alt;
    }
    return sum % 10 == 0;
}

int validate_transaction(const Transaction* tx) {
    if (!luhn_check(tx->card_number)) {
        printf("Invalid card number (failed Luhn check)\n");
        return 0;
    }

    if (tx->amount <= 0) {
        printf("Invalid amount\n");
        return 0;
    }

    return 1;
}
