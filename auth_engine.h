#ifndef AUTH_ENGINE_H_INCLUDED
#define AUTH_ENGINE_H_INCLUDED
#include "transaction.h"

typedef enum {
    AUTH_APPROVED,
    AUTH_DECLINED,
    AUTH_FLAGGED
} AuthResult;

AuthResult authorize_transaction(const Transaction* tx);

#endif // AUTH_ENGINE_H_INCLUDED
