void generateStatement(struct Admin* admin) {

    STATEMENT statement;

    FILE* statementFile = fopen(STATEMENTS_FILE, "r");

    char acctNum[20];
    int found=0;
    printf("Enter the ACCOUNT NUMBER you want to get transaction Details : ");
    scanf("%s",acctNum);

    char startDate[11];
    char endDate[11];
    printf("Enter the start date (DD/MM/YYYY): ");
    scanf("%s", startDate);
    printf("Enter the end date (DD/MM/YYYY): ");
    scanf("%s", endDate);

    printf("\n=============================================== || ATM STATEMENT || =================================================\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("   ACCOUNT NUMBER\tTRANSACTION DATE\tTRANSACTION ID\t\tTRANSACTION TYPE\tBALANCE \n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
       
    while (fscanf(statementFile, "%[^,],%[^,],%u,%[^,],%lf\n", statement.accountNumber, statement.date, &statement.transactionId, statement.transactionType, &statement.balance) != EOF) {
        int startDay, startMonth, startYear, endDay, endMonth, endYear, transDay, transMonth, transYear;
        sscanf(startDate, "%d/%d/%d", &startDay, &startMonth, &startYear);
        sscanf(endDate, "%d/%d/%d", &endDay, &endMonth, &endYear);
        sscanf(statement.date, "%d/%d/%d", &transDay, &transMonth, &transYear);

        if (strcmp(acctNum, statement.accountNumber) == 0 &&
            (transYear > startYear || (transYear == startYear && (transMonth > startMonth || (transMonth == startMonth && transDay >= startDay)))) &&
            (transYear < endYear || (transYear == endYear && (transMonth < endMonth || (transMonth == endMonth && transDay <= endDay))))
        ) {
            found = 1;
            printf("     %-15s    %-15s  \t %u\t\t %-15s  \t%.2lf\n", statement.accountNumber, statement.date, statement.transactionId, statement.transactionType, statement.balance);
        }
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    fclose(statementFile);


    if(found == 0) {

        printf("\nRecord not found!!!\n");
        printf("-------------------------------\n");
        int choice;
        
        transaction_invalid:
        printf("1. Try Again\n");
        printf("2. Back to Main Menu\n");
        printf("3. Cancel and Logout\n");
        printf("-> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateStatement(admin);
                break;
            case 2:
                adminMenu(admin);
                break;
            case 3:
                adminLogout(admin);
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                goto transaction_invalid;
        }
    } else {
        int choice;
        
        printf("1. Main Menu\n");
        printf("2. Logout and Exit\n");
        printf("-------------------------------\n");
        printf("-> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                adminMenu(admin);
                break;
            case 2:
                adminLogout(admin);
                exit(0);
        }
    }
}