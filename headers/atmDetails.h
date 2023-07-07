#define MAX_STATE_LENGTH 50
#define MAX_CITY_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_BANK_NAME_LENGTH 50
#define MAX_ATM_ID_LENGTH 50
#define ATM_DETAILS_FILENAME "../data/ATMs.csv"
#define DELETED_ATM_FILE "../data/DeletedATMs.csv"
#define ATM_DETAILS_TEMP_FILE "../data/ATMtemp.csv"
#define TRANSACTION_DETAILS_FILENAME "../data/transactions.csv"

typedef struct {
    char state[MAX_STATE_LENGTH];
    char city[MAX_CITY_LENGTH];
    char type[10];
    char address[MAX_ADDRESS_LENGTH];
} ATM;