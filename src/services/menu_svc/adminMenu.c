void adminMenu(struct Admin* admin) {

    system("clear");

    int choice=0;
    char input[100];
    
    do {
        printf("=========================================================================================\n");
        printf("\t\t\t\tAutomated Teller Machine\n");
        printf("\t\t\t\t Administration Module\n");
        printf("=========================================================================================\n");
        printf("1.  Add ATM\n");
        printf("2.  Update ATM\n");
        printf("3.  Delete ATM\n");
        printf("4.  Search ATM & Transactions\n");
        printf("5.  Add customer\n");
        printf("6.  Close an Account\n");
        printf("7.  Approve / Deny Cheque(s)\n");
        printf("8.  Account Statement\n");
        printf("9.  Logout and Exit\n");
        printf("10. Cancel Transaction\n");
        printf("-------------------------------\n");
        printf("Enter Your Choice -> ");

        scanf("%s", input);

            if (!validateInteger(input)) {
                printf("Invalid input! Please enter a valid integer.\n");
                continue;
            }

        choice = atoi(input);

        switch (choice) {
            case 1:
                // Add an ATM
                addATM();
                break;
            case 2:
                // Update an ATM
                break;
            case 3:
                // Delete an ATM
                deleteATM();
                break;
            case 4:
                // Search ATM & Transactions
                viewTransactionsOfATM();
                break;
            case 5:
                // Add customer
                addAccount();
                break;
            case 6:
                // Close an Account
                closeAccount();
                break;
            case 7:
                // Approve / Deny Cheque(s)
                verifyAndClearCheck(admin);
                break;
            case 8:
                // Account Statement
                generateStatement(admin);
                break;
            case 9:
                if (confirmChoice()) {
                    adminLogout(admin);
                    mainMenu();
                } else {
                    printf("Logout canceled. Continuing session.\n");
                    adminMenu(admin);
                    return;
                }
                break;
            case 10:
                system("clear");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
    } while (choice != 10);
}