#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#define MAX_CARD_LENGTH 20
#define MAX_CURRENCY_LENGTH 4
#define MAX_TRANSACTIONS 100

typedef struct {
    char card_number[MAX_CARD_LENGTH];
    char expiry_date[6]; // MM/YY
    float amount;
    char currency[MAX_CURRENCY_LENGTH];
} Transaction;

int load_transactions(const char* filename, Transaction* transactions, int max_transactions);


#endif // TRANSACTION_H_INCLUDED
