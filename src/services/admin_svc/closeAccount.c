void closeAccount() {
    unsigned int accountNumber;

    printf("Enter the account number to delete: ");
    scanf("%u", &accountNumber);

    // Check if the account exists
    if (isAccountExists(accountNumber)) {
        // Confirm account closure with the Administrator
        char confirmation;
        printf("Are you sure you want to close the account (Y/N)? ");
        clearInputBuffer();
        scanf("%c", &confirmation);

        if (confirmation == 'Y' || confirmation == 'y') {
            // Perform the account closure
            if (isAccountClosed(accountNumber)) {
                printf("Account with account number %u has been successfully closed.\n", accountNumber);
            } else {
                printf("Failed to close the account. Please try again later.\n");
            }
        } else {
            printf("Account closure canceled.\n");
        }
    } else {
        printf("Account with account number %u does not exist.\n", accountNumber);
    }
}


// Function to check if an account exists
int isAccountExists(unsigned int accountNumber) {
    // Open the customer details file for reading
    FILE* file = fopen(CUSTOMER_DETAILS, "r");
    if (file == NULL) {
        printf("Failed to open Customers.csv for reading.\n");
        return 0;
    }

    // Search for the account number in the file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        unsigned int currentAccountNumber;
        sscanf(line, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%u,%*[^,],%*[^,],%*[^,],%*[^,]",&currentAccountNumber);
        if (currentAccountNumber == accountNumber) {
            fclose(file);
            return 1; // Account exists
        }
    }

    fclose(file);
    return 0; // Account does not exist
}

// Function to close an account
int isAccountClosed(unsigned int accountNumber) {
    // Open the customer details file for reading and a temporary file for writing
    FILE* inputFile = fopen(CUSTOMER_DETAILS, "r");
    FILE* tempFile = fopen("../data/temp.csv", "w");
    if (inputFile == NULL || tempFile == NULL) {
        printf("Failed to open files for account closure.\n");
        return 0;
    }

    // Copy the data from the input file to the temporary file, excluding the account to be closed
    char line[256];
    int accountFound = 0;
    while (fgets(line, sizeof(line), inputFile)) {
        unsigned int currentAccountNumber;
        sscanf(line, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%u,%*[^,],%*[^,],%*[^,],%*[^,]",&currentAccountNumber);
        if (currentAccountNumber == accountNumber) {
            accountFound = 1;
            continue; // Skip writing the line for the account to be closed
        }
        fprintf(tempFile, "%s", line); // Write the line to the temporary file
    }

    fclose(inputFile);
    fclose(tempFile);

    if (!accountFound) {
        remove("../data/temp.csv"); // Delete the temporary file
        return 0; // Account not found
    }

    // Replace the original file with the temporary file
    if (remove(CUSTOMER_DETAILS) != 0) {
        printf("Failed to delete the account from Customers.csv.\n");
        return 0;
    }
    if (rename("../data/temp.csv", CUSTOMER_DETAILS) != 0) {
        printf("Failed to update Customers.csv after account closure.\n");
        return 0;
    }

    return 1; // Account closure successful
}
