#include <stdio.h>
#include <string.h>
#include "auth_engine.h"
#include "validator.h"
#include "compliance.h"

const char* blocked_card_number = "4111111111111111";

AuthResult authorize_transaction(const Transaction* tx) {
    if (!validate_transaction(tx)) {
        return AUTH_DECLINED;
    }

    if (!check_compliance(tx)) {
        return AUTH_DECLINED;
    }

    if (strcmp(tx->card_number, blocked_card_number) == 0) {
        printf("Transaction flagged for fraud review.\n");
        return AUTH_FLAGGED;
    }

    return AUTH_APPROVED;
}
