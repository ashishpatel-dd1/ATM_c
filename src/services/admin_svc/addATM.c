void addATM() {

    ATM* atm = malloc(sizeof(ATM));
    if (atm == NULL) {
        printf("Failed to allocate memory for ATM.\n");
        return;
    }

    printf("-------------------------------\n");


//---------------------------------------------------------------STATE---------------------------------------------------------------//

    printf("Enter State: ");
    clearInputBuffer();
    fgets(atm->state, sizeof(atm->state), stdin);
    atm->state[strcspn(atm->state, "\n")] = '\0';  // Remove newline character


    // Validate State
    if (atm->state[0] == '\0' || !validateAlphabetsOnly(atm->state)) {
        printf("Invalid State. Please enter alphabets only.\n");
        free(atm);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------CITY---------------------------------------------------------------//
    
    printf("Enter City: ");
    // clearInputBuffer();
    fgets(atm->city, sizeof(atm->city), stdin);
    atm->city[strcspn(atm->city, "\n")] = '\0';  // Remove newline character


    // Validate City
    if (atm->city[0] == '\0' || !validateAlphabetsOnly(atm->city)) {
        printf("Invalid City. Please enter alphabets only.\n");
        free(atm);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ATM TYPE---------------------------------------------------------------//

    printf("Enter Type (Urban or Rural): ");
    // clearInputBuffer();
    fgets(atm->type, sizeof(atm->type), stdin);
    atm->type[strcspn(atm->type, "\n")] = '\0';  // Remove newline character


    // Validate Type
    if (strcmp(atm->type, "Urban") != 0 && strcmp(atm->type, "Rural") != 0) {
        printf("Invalid Type. Please enter either Urban or Rural.\n");
        free(atm);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ADDRESS---------------------------------------------------------------//

    printf("Enter Address: ");
    // clearInputBuffer();
    fgets(atm->address, sizeof(atm->address), stdin);
    atm->address[strcspn(atm->address, "\n")] = '\0';  // Remove newline character

    // Validate Address
    if (atm->address[0] == '\0') {
        printf("Address cannot be empty.\n");
        free(atm);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------//

    
    // All validations passed
    printf("ATM details captured successfully!\n");

    printf("------------------------------------\n");

    // Generate ATM ID
    char bankName[MAX_BANK_NAME_LENGTH];
    printf("Enter Bank Name: ");
    fgets(bankName, sizeof(bankName), stdin);
    bankName[strcspn(bankName, "\n")] = '\0';  // Remove newline character
    //printf("%s", bankName);

    // Extract first character from each word of bank name
    char* token = strtok(bankName, " ");
    char bankID[10] = "";
    while (token != NULL) {
        strncat(bankID, &token[0], 1);
        token = strtok(NULL, " ");
    }
    int atmCount = 2; 

    // Generate ATM ID
    char atmID[50];
    snprintf(atmID, sizeof(atmID), "%s-%.3s-%.3s-%.3s-%d", bankID, atm->type, atm->state, atm->city, atmCount);
    for (int i = 0; atmID[i]; i++) {
        atmID[i] = toupper(atmID[i]);
    }

    // Write ATM details to file
    FILE* file = fopen(ATM_DETAILS_FILENAME, "a");
    if (file != NULL) {
        long fileSize = ftell(file);
        if (fileSize == 0) {
            // File is empty, write the header
            fprintf(file, "ATM ID,STATE,CITY,TYPE,ADDRESS\n");
        }
        fprintf(file, "%s,%s,%s,%s,%s\n", atmID, atm->state, atm->city, atm->type, atm->address);
        fclose(file);
        printf("ATM details written to ATMs.csv\n");
    } else {
        printf("Failed to open ATMs.csv for writing.\n");
    }

    printf("-------------------------------\n");

    free(atm);
}