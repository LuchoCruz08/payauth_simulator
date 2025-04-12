#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED
#include "transaction.h"
#include "auth_engine.h"

void init_logger(const char* filename);
void log_transaction(const Transaction* tx, AuthResult result);
void close_logger(void);
void print_summary_report(void);

#endif // LOGGER_H_INCLUDED
