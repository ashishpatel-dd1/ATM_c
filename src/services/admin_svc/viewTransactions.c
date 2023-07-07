void viewTransactionsOfATM() {
    char state[MAX_STATE_LENGTH];
    char city[MAX_CITY_LENGTH];
    char type[10];
    char atmID[MAX_ATM_ID_LENGTH];

    printf("Enter State: ");
    clearInputBuffer();
    fgets(state, sizeof(state), stdin);
    state[strcspn(state, "\n")] = '\0';

    printf("Enter City: ");
    fgets(city, sizeof(city), stdin);
    city[strcspn(city, "\n")] = '\0';

    printf("Enter Type: ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0';

    printf("Enter ATM ID: ");
    fgets(atmID, sizeof(atmID), stdin);
    atmID[strcspn(atmID, "\n")] = '\0';
    printf("---------------------------\n");


    FILE* atmFile = fopen(ATM_DETAILS_FILENAME, "r");
    if (atmFile == NULL) {
        printf("Failed to open ATMs.csv for reading.\n");
        return;
    }

    // Check if the ATM ID exists in the ATMs file
    int foundATM = 0;
    char atmLine[256];
    while (fgets(atmLine, sizeof(atmLine), atmFile)) {
        char atmId[MAX_ATM_ID_LENGTH];
        sscanf(atmLine, "%[^,]", atmId);
        if (strcmp(atmId, atmID) == 0) {
            foundATM = 1;
            break;
        }
    }

    fclose(atmFile);

    if (!foundATM) {
        printf("ATM ID not found.\n");
        return;
    }

    displayATM(state, city, type);

    FILE* transactionFile = fopen(TRANSACTION_DETAILS_FILENAME, "r");
    if (transactionFile == NULL) {
        printf("Failed to open Transactions.csv for reading.\n");
        return;
    }

    // Display transactions for the current ATM ID
    char transactionLine[256];
    int foundTransaction = 0;  // Variable to keep track of whether any transactions are found or not
    while (fgets(transactionLine, sizeof(transactionLine), transactionFile)) {
        char transactionATMID[MAX_ATM_ID_LENGTH];
        char transactionDate[11];
        char transactionAmount[10];
        char transactionDescription[100];

        sscanf(transactionLine, "%[^,],%[^,],%[^,],%[^\n]", transactionATMID, transactionDate, transactionAmount, transactionDescription);
        
        // Check if the transaction belongs to the current ATM ID
        if (strcmp(transactionATMID, atmID) == 0) {
            printf("---------------------------\n");
            printf("ATM ID: %s\n", transactionATMID);
            printf("Transaction Date: %s\n", transactionDate);
            printf("Amount: %s\n", transactionAmount);
            printf("Description: %s\n", transactionDescription);
            printf("---------------------------\n");
            foundTransaction = 1;  // At least one transaction is found
        }
    }

    if (!foundTransaction) {
        printf("No transactions found for the ATM ID: %s\n", atmID);
    }

    fclose(transactionFile);
}
