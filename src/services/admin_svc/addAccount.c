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
    if (customer->fullName[0] == '\0' || !validateAlphabetsOnly(customer->fullName)) {
        printf("Invalid Full Name. Please enter alphabets only.\n");
        free(customer);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------FATHER'S NAME---------------------------------------------------------------//

    printf("Enter Father's Name: ");
    fgets(customer->fathersName, 50, stdin);
    customer->fathersName[strcspn(customer->fathersName, "\n")] = '\0';

    // Validate Father's Name
    if (customer->fathersName[0] == '\0' || !validateAlphabetsOnly(customer->fathersName)) {
        printf("Invalid. Please enter alphabets only.\n");
        free(customer);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------DOB---------------------------------------------------------------//

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(customer->dob, 50, stdin);
    customer->dob[strcspn(customer->dob, "\n")] = '\0';

    // Validate DOB
    if (customer->dob[0] == '\0' || !validateDateOfBirth(customer->dob)) {
        printf("Invalid Date of Birth. Please enter in the format DD/MM/YYYY.\n");
        free(customer);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------GENDER---------------------------------------------------------------//

    printf("Enter Gender: ");
    fgets(customer->gender, 50, stdin);
    customer->gender[strcspn(customer->gender, "\n")] = '\0';

    // Validate Gender
    if (customer->gender[0] == '\0' || !validateGender(customer->gender)) {
        printf("Invalid gender. Please enter 'male' or 'female'.\n");
        free(customer);
        return;
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
    if (customer->panCardNo[0] == '\0' || !validatePanCard(customer->panCardNo)) {
        printf("Invalid PAN Card No.\n%s", customer->panCardNo);
        free(customer);
        return;
    }

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------LANDLINE NUMBER---------------------------------------------------------------//

    printf("Enter Landline: ");
    clearInputBuffer();
    fgets(customer->landline, 50, stdin);
    customer->landline[strcspn(customer->landline, "\n")] = '\0';

//-----------------------------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------MOBILE NUMBER---------------------------------------------------------------//

    printf("Enter Mobile: ");
    fgets(customer->mobile, 50, stdin);
    customer->mobile[strcspn(customer->mobile, "\n")] = '\0';

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
    if (customer->accountType[0] == '\0' || !validateAccountType(customer->accountType)) {
        printf("Invalid account type. Please enter 'salary' or 'savings' or 'current'.\n");
        free(customer);
        return;
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
        printf("Account Number: %u\n", customer->accountNumber);
        printf("Customer Number: %u\n", customer->customerNumber);
        printf("Card Number: %llu\n", customer->cardNumber);
        //printf("PIN: %u\n", customer->pin);
        if (customer->hasCheckBook) {
            printf("Chequebook Number: %u\n", customer->chequebookNumber);
            printf("\nCheck Book Added Successfully!\n");
        }
    } else {
        printf("Failed to open Customers.csv for writing.\n");
    }

    // Free allocated memory
    free(customer);
}