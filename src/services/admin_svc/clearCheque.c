void verifyAndClearCheck(struct Admin* admin) {
    CHEQUE cheque;

    FILE *fp = fopen(CHEQUEBOOK_DETAILS, "r");
    FILE *fp1 = fopen("../data/temp.csv", "a+");
    int found = 0;
    unsigned int chequeId;
    
    printf("-------------------------------\n");
    printf("Enter cheque Id which you want to verify: ");
    if (scanf("%u", &chequeId) != 1) {
        // Invalid input
        while (getchar() != '\n');
        printf("Invalid input for cheque Id. Please enter a valid Cheque Id\n");
        verifyAndClearCheck(admin);
        return;
    }
    
    while (fscanf(fp, "%u,%u,%lf,%[^,],%[^\n]\n", &cheque.chequeId, &cheque.accountNumber, &cheque.amount, cheque.accountType, cheque.status) != EOF) {
        if (chequeId == cheque.chequeId) {
            found = 1;
            printf("Approve or Deny: ");
            scanf("%s", cheque.status);
        }
        fprintf(fp1, "%u,%u,%.2lf,%s,%s\n", cheque.chequeId, cheque.accountNumber, cheque.amount, cheque.accountType, cheque.status);
    }

    fclose(fp);
    fclose(fp1);
    remove(CHEQUEBOOK_DETAILS);
    rename("../data/temp.csv", CHEQUEBOOK_DETAILS);

    if (found == 0) {
        printf("\nRecord not found!!!\n");
        printf("-------------------------------\n");
        int choice;
        
        varify_invalid:
        printf("1. Try Again\n");
        printf("2. Back to Main Menu\n");
        printf("3. Cancel Transaction\n");
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
                goto varify_invalid;
        }
    } else {
        int choice;
        printf("-------------------------------\n");
        printf("1. Main Menu\n");
        printf("2. Cancel Transaction and Exit\n");
        printf("-> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                adminMenu(admin);
                break;
            case 2:
                exit(0);
        }
    }
}
