#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PAN_LENGTH 10
#define MAX_BRANCH_LENGTH 50
#define CUSTOMER_DETAILS "../data/Customers.csv"
#define CHEQUEBOOK_DETAILS "../data/Chequebook.csv"
#define STATEMENTS_FILE "../data/Statements.csv"

typedef struct {
    char fullName[MAX_NAME_LENGTH];
    char fathersName[MAX_NAME_LENGTH];
    char dob[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];
    char permanentAddress[MAX_ADDRESS_LENGTH];
    char presentAddress[MAX_ADDRESS_LENGTH];
    char panCardNo[MAX_PAN_LENGTH];
    char landline[MAX_NAME_LENGTH];
    char mobile[MAX_NAME_LENGTH];
    int hasCheckBook;
    char accountType[MAX_NAME_LENGTH];
    double openingBalance;
    char branchName[MAX_BRANCH_LENGTH];
    unsigned int accountNumber;
    unsigned int customerNumber;
    unsigned long long cardNumber;
    unsigned int pin;
    unsigned int chequebookNumber;
} CUSTOMER;

typedef struct {
    unsigned int chequeId;
    unsigned int accountNumber;
    double amount;
    char accountType[50];
    char status[20];
} CHEQUE;

typedef struct {
   char accountNumber[11];
   char date[10];
   unsigned int transactionId;
   char transactionType[10];
   double balance; 
} STATEMENT;