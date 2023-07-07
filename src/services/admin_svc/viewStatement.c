void generateStatement(struct Admin* admin) {

    STATEMENT statement;

    FILE* fp1 = fopen(STATEMENTS_FILE, "r");

    char acctNum[20];
    int found=0;
    printf("Enter the ACCOUNT NUMBER you want to get transaction Details : ");
    scanf("%s",acctNum);

       
    while(fscanf(fp1,"%[^,],%[^,],%u,%[^,],%lf\n" , statement.accountNumber, statement.date, &statement.transactionId, statement.transactionType, &statement.balance) != EOF)
    {
        //printf("ACCount NU  : %d\n",addAcc.accountno);
        if(strcmp(acctNum, statement.accountNumber)==0)
        {
            found=1;
            //printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%.2lf\n",addAcc.accountno, addAcc.transactionDate, addAcc.name, addAcc.type,  addAcc.transactionId, addAcc.status, addAcc.balance);
        }
    }

    fclose(fp1);
    
    FILE* statementFile = fopen(STATEMENTS_FILE, "r");

    if (found == 1) {
        printf("\n=============================================== || ATM STATEMENT || =================================================\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        printf("   ACCOUNT NUMBER\tTRANSACTION DATE\tTRANSACTION ID\t\tTRANSACTION TYPE\tBALANCE \n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");

        while (fscanf(statementFile, "%[^,],%[^,],%u,%[^,],%lf\n", statement.accountNumber, statement.date, &statement.transactionId, statement.transactionType, &statement.balance) != EOF) {
            if (strcmp(acctNum, statement.accountNumber) == 0) {
                printf("     %-15s    %-15s  \t %u\t\t %-15s  \t%.2lf\n", statement.accountNumber, statement.date, statement.transactionId, statement.transactionType, statement.balance);
            }
        }
        printf("---------------------------------------------------------------------------------------------------------------------\n");
    }


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
                verifyAndClearCheck(admin);
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