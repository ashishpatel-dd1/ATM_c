void mainMenu() {

    system("clear");
    int choice=0;
    char input[100];
    
    do {
            printf("=========================================================================================\n");
            printf("\t\t\t\tAutomated Teller Machine\n");
            printf("=========================================================================================\n");
            printf("1. Admin Login\n");
            printf("2. Customer Login\n");
            printf("3. Cancel Transaction\n");
            printf("---------------------------\n");
            printf("Enter Your Choice -> ");
            
            scanf("%s", input);

            if (!validateInteger(input)) {
                printf("Invalid input! Please enter a valid integer.\n");
                continue;
            }

        choice = atoi(input);
            
            switch(choice)
            {
                case 1:
                {
                    adminLogin();
                    break;
                }
                case 2:
                {
                    // Customer login
                    break;
                }
                case 3:
                {
                    printf("Cancel transaction ! ");
                    if(confirmChoice())
                        exit(0);
                    else {
                        mainMenu();
                        return;
                    }
                    break;
                }
                default:
                printf("INVALID CHOICE !!\n");
            }
    } while(choice!=3);

}