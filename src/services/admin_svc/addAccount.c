void generateUniqueNumbers(CUSTOMER* customer) {
    // Generate unique numbers for account, customer, card, and PIN
    static unsigned int accountCount = 1000;
    static unsigned int customerCount = 1000;
    static unsigned int cardCount = 1000;

    // Generate random numbers for account, customer, and card
    customer->accountNumber = rand() % 9000000000 + 1000000000; // Generate a 10-digit account number
    customer->customerNumber = rand() % 900000 + 100000; // Generate a 6-digit customer number
    customer->cardNumber = rand() % 900000000000 + 100000000000; // Generate an 12-digit card number

    // Generate a random 4-digit PIN
    customer->pin = rand() % 9000 + 1000;
}


void addAccount() {

    CUSTOMER* customer = malloc(sizeof(CUSTOMER));
    printf("-------------------------------\n");

    
//---------------------------------------------------------------FULL NAME---------------------------------------------------------------//

    printf("Enter Full Name: ");
    clearInputBuffer();
    fgets(customer->fullName, 50, stdin);
    customer->fullName[strcspn(customer->fullName, "\n")] = '\0';

    // Validate Full Name
    while (customer->fullName[0] == '\0' || !validateAlphabetsOnly(customer->fullName)) {
        printf("Invalid Full Name.\nPlease enter a valid Full Name: ");
        fgets(customer->fullName, 50, stdin);
        customer->fullName[strcspn(customer->fullName, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------FATHER'S NAME---------------------------------------------------------------//

    printf("Enter Father's Name: ");
    fgets(customer->fathersName, 50, stdin);
    customer->fathersName[strcspn(customer->fathersName, "\n")] = '\0';

    // Validate Father's Name
    while (customer->fathersName[0] == '\0' || !validateAlphabetsOnly(customer->fathersName)) {
        printf("Invalid.\nPlease enter a valid Name: ");
        fgets(customer->fathersName, 50, stdin);
        customer->fathersName[strcspn(customer->fathersName, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------DOB---------------------------------------------------------------//

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(customer->dob, 50, stdin);
    customer->dob[strcspn(customer->dob, "\n")] = '\0';

    // Validate DOB
    while (customer->dob[0] == '\0' || !validateDateOfBirth(customer->dob)) {
        printf("Invalid Date of Birth.\nPlease enter in the format [DD/MM/YYYY]: ");
        fgets(customer->dob, 50, stdin);
        customer->dob[strcspn(customer->dob, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------GENDER---------------------------------------------------------------//

    printf("Enter Gender: ");
    fgets(customer->gender, 50, stdin);
    customer->gender[strcspn(customer->gender, "\n")] = '\0';

    // Validate Gender
    while (customer->gender[0] == '\0' || !validateGender(customer->gender)) {
        printf("Invalid gender.\nPlease enter [male] or [female]: ");
        fgets(customer->gender, 50, stdin);
        customer->gender[strcspn(customer->gender, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------PERMANENT ADDRESS---------------------------------------------------------------//

    printf("Enter Permanent Address: ");
    fgets(customer->permanentAddress, 100, stdin);
    customer->permanentAddress[strcspn(customer->permanentAddress, "\n")] = '\0';

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------PRESENT ADDRESS---------------------------------------------------------------//

    printf("Enter Present Address: ");
    fgets(customer->presentAddress, 100, stdin);
    customer->presentAddress[strcspn(customer->presentAddress, "\n")] = '\0';

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------PAN CARD---------------------------------------------------------------//

    printf("Enter PAN Card No.: ");
    fgets(customer->panCardNo, 11, stdin);
    customer->panCardNo[strcspn(customer->panCardNo, "\n")] = '\0';

    // Validate PAN CARD
    while (customer->panCardNo[0] == '\0' || !validatePanCard(customer->panCardNo)) {
        printf("Invalid PAN Card No. | %s.\nEnter a valid PAN Card Number: ", customer->panCardNo);
        fgets(customer->panCardNo, 11, stdin);
        customer->panCardNo[strcspn(customer->panCardNo, "\n")] = '\0';
    }
    
//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------LANDLINE NUMBER---------------------------------------------------------------//

    printf("Enter Landline: ");
    fgets(customer->landline, 11, stdin);
    customer->landline[strcspn(customer->landline, "\n")] = '\0';

    // Validate Landline Number
    while (customer->landline[0] == '\0' || !validateInteger(customer->landline)) {
        printf("Landline Number is invalid or contains non-numeric characters.\nPlease enter a valid landline number: ");
        fgets(customer->landline, sizeof(customer->landline), stdin);
        customer->landline[strcspn(customer->landline, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------MOBILE NUMBER---------------------------------------------------------------//

    printf("Enter Mobile Number: ");
    fgets(customer->mobile, 11, stdin);
    customer->mobile[strcspn(customer->mobile, "\n")] = '\0';
    
    // Validate Monile Number
    while (customer->mobile[0] == '\0' || !validateInteger(customer->mobile)) {
        printf("Mobile Number is invalid or contains non-numeric characters.\nPlease enter a valid Mobile Number: ");
        fgets(customer->mobile, sizeof(customer->mobile), stdin);
        customer->mobile[strcspn(customer->mobile, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------CHEQUEBOOK---------------------------------------------------------------//

    printf("Do you want a Check Book? (1 for Yes, 0 for No): ");
    scanf("%d", &customer->hasCheckBook);
    getchar();
    if (customer->hasCheckBook) {
        // Generate a random 6-digit chequebook number
        customer->chequebookNumber = rand() % 900000 + 100000;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------ACCOUNT TYPE---------------------------------------------------------------//

    printf("Enter Account Type: ");
    fgets(customer->accountType, 50, stdin);
    customer->accountType[strcspn(customer->accountType, "\n")] = '\0';

    // Validate Account Type
    while (customer->accountType[0] == '\0' || !validateAccountType(customer->accountType)) {
        printf("Invalid account type.\nPlease enter [salary] or [savings] or [current]: ");
        fgets(customer->accountType, 50, stdin);
        customer->accountType[strcspn(customer->accountType, "\n")] = '\0';
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------OPENING BALANCE---------------------------------------------------------------//

    printf("Enter Opening Balance: ");
    scanf("%lf", &customer->openingBalance);
    getchar();

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------BRANCH NAME---------------------------------------------------------------//

    printf("Enter Branch Name: ");
    fgets(customer->branchName, 50, stdin);
    customer->branchName[strcspn(customer->branchName, "\n")] = '\0';

//-----------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------//

    // Generate unique numbers for account, customer, card, and PIN
    generateUniqueNumbers(customer);

    // Save the customer details to the "Customers.csv" file
    FILE* file = fopen(CUSTOMER_DETAILS, "a");
    if (file != NULL) {
        long fileSize = ftell(file);
        if (fileSize == 0) {
            // File is empty, write the header
            fprintf(file, "Full Name,Father's Name,Date of Birth,Gender,Permanent Address,Present Address,PAN Card No.,Landline,Mobile,Check Book,Account Type,Opening Balance,Branch Name,Account Number,Customer Number,Card Number,PIN,Chequebook Number\n");
        } 
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%s,%.2f,%s,%u,%u,%llu,%u,%u\n",
                customer->fullName, customer->fathersName, customer->dob, customer->gender, customer->permanentAddress,
                customer->presentAddress, customer->panCardNo, customer->landline, customer->mobile, customer->hasCheckBook,
                customer->accountType, customer->openingBalance, customer->branchName,
                customer->accountNumber, customer->customerNumber, customer->cardNumber, customer->pin, customer->chequebookNumber);
        fclose(file);
        printf("\nAccount Creation Successful!\n");
        printf("Account Number:    | %u\n", customer->accountNumber);
        printf("Customer Number:   | %u\n", customer->customerNumber);
        printf("Card Number:       | %llu\n", customer->cardNumber);
        //printf("PIN: %u\n", customer->pin);
        if (customer->hasCheckBook) {
            printf("Chequebook Number: | %u\n", customer->chequebookNumber);
            printf("\nCheck Book Added Successfully!\n");
        }
    } else {
        printf("Failed to opem file.\n");
    }

    // Free allocated memory
    free(customer);
}