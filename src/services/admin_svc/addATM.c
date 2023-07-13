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
    atm->state[strcspn(atm->state, "\n")] = '\0';


    // Validate State
    while (atm->state[0] == '\0' || !validateAlphabetsOnly(atm->state)) {
        printf("Invalid State.\nPlease enter a valid State: ");
        fgets(atm->state, sizeof(atm->state), stdin);
        atm->state[strcspn(atm->state, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------CITY---------------------------------------------------------------//
    
    printf("Enter City: ");
    fgets(atm->city, sizeof(atm->city), stdin);
    atm->city[strcspn(atm->city, "\n")] = '\0';


    // Validate City
    while (atm->city[0] == '\0' || !validateAlphabetsOnly(atm->city)) {
        printf("Invalid City.\nPlease enter a valid City: ");
        fgets(atm->city, sizeof(atm->city), stdin);
        atm->city[strcspn(atm->city, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ATM TYPE---------------------------------------------------------------//

    printf("Enter Type (Urban or Rural): ");
    fgets(atm->type, sizeof(atm->type), stdin);
    atm->type[strcspn(atm->type, "\n")] = '\0';


    // Validate Type
    while (strcmp(atm->type, "Urban") != 0 && strcmp(atm->type, "Rural") != 0) {
        printf("Invalid Type. Please enter either [Urban] or [Rural]: \n");
        fgets(atm->type, sizeof(atm->type), stdin);
        atm->type[strcspn(atm->type, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ADDRESS---------------------------------------------------------------//

    printf("Enter Address: ");
    fgets(atm->address, sizeof(atm->address), stdin);
    atm->address[strcspn(atm->address, "\n")] = '\0';

    // Validate Address
    while (atm->address[0] == '\0') {
        printf("Address cannot be empty: ");
        fgets(atm->address, sizeof(atm->address), stdin);
        atm->address[strcspn(atm->address, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ATM-ID---------------------------------------------------------------//
   
    // Generate ATM ID
    char bankName[MAX_BANK_NAME_LENGTH];
    printf("Enter Bank Name: ");
    fgets(bankName, sizeof(bankName), stdin);
    bankName[strcspn(bankName, "\n")] = '\0';
    //printf("%s", bankName);

    
    char* token = strtok(bankName, " ");
    char bankID[10] = "";
    while (token != NULL) {
        strncat(bankID, &token[0], 1);
        token = strtok(NULL, " ");
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ATM COUNT---------------------------------------------------------------//
    
    srand(time(NULL));  // Seed the random number generator
    int atmCount = rand() % 90 + 10;  // Generate a random number between 10 and 99

//-----------------------------------------------------------------------------------------------------------------------------------//

    // All validations passed
    printf("ATM details captured successfully!\n");
    printf("------------------------------------\n");

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
        //printf("ATM details written to ATMs.csv\n");
    } else {
        printf("Failed to open file for writing.\n");
    }

    printf("-------------------------------\n");

    free(atm);
}