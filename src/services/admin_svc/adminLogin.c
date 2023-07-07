void changePassword(struct Admin* admin, int isFirstTimeLogin) {
    if (isFirstTimeLogin) {
        printf("Enter new password: ");
        scanf("%s", admin->password);
        printf("Password changed successfully!\n");
    } else {
        printf("Password change is only allowed during the first-time login.\n");
    }
}

void updateLoginStatus(struct Admin* admin) {
    admin->login_status = 1;
    FILE* file = fopen(LOGINS_FILENAME, "w");
    if (file != NULL) {
        long fileSize = ftell(file);
        if (fileSize == 0) {
            // File is empty, write the header
            fprintf(file, "Username,Password,OTP,LoginStatus\n");
        }
        fprintf(file, "%s,%s,%d,%d\n", admin->username, admin->password, admin->otp, admin->login_status);
        fclose(file);
        //printf("Login status updated in Logins.csv.\n");
        //printf("Redirecting to Administrator Module...\n");
    } else {
        printf("Failed to update login status in Logins.csv.\n");
    }
}


int generateOTP() {
    srand(time(0));
    return rand() % 900000 + 100000;
}

void adminLogin() {

    printf("---------------------------\n");

    struct Admin* head = createAdminNode();
    struct Admin* current = head;

    FILE* file = fopen(LOGINS_FILENAME, "r");
    if (file != NULL) {
        // Skip header row
        char buffer[100];
        fgets(buffer, sizeof(buffer), file);

        if (feof(file)) {
            fclose(file);
            printf("No admin user found. Creating a new admin user.\n");

            struct Admin* newNode = createAdminNode();
            if (newNode == NULL) {
                printf("Failed to create a new admin user.\n");
                free(head);
                return;
            }

            printf("Enter username: ");
            scanf("%s", newNode->username);

            printf("Enter password: ");
            scanf("%s", newNode->password);

            printf("---------------------------\n");

            newNode->otp = generateOTP();
            newNode->login_status = 0;

            current->next = newNode;
            current = newNode;

            updateLoginStatus(current);

            printf("Admin user created successfully.\n");
            adminMenu(current);
            return;
        }

        while (!feof(file)) {
            struct Admin* newNode = createAdminNode();
            if (newNode != NULL) {
                if (fscanf(file, "%[^,],%[^,],%d,%d", newNode->username, newNode->password, &newNode->otp, &newNode->login_status) == 4) {
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
        fclose(file);
    } else {
        printf("Failed to open Logins.csv for reading.\n");
        return;
    }

    int otp;
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("---------------------------\n");

    current = head->next;
    while (current != NULL) {
        if (strcmp(username, current->username) == 0 && strcmp(password, current->password) == 0) {

            if (current->login_status == 1) {
                printf("You are already logged in.\n");

                if (confirmChoice()) {
                    printf("Logout canceled. Continuing session.\n");
                    adminMenu(current);
                    return;
                } else {
                    adminLogout(current);
                }
            }

            if (current->login_status == 0) {
                current->otp = generateOTP();
                printf("OTP: %d\n", current->otp);

                printf("Enter OTP: ");
                scanf("%d", &otp);
                if (otp == current->otp) {
                    printf("Login successful!\n");
                    changePassword(current, 0);  // First-time login
                    updateLoginStatus(current);
                    adminMenu(current);
                    return;
                } else {
                    printf("Invalid OTP. Login failed.\n");
                    return;
                }
            } else {
                printf("Login successful!\n");
                adminMenu(current);
                return;
            }
        }
        current = current->next;
    }

    printf("Invalid username or password. Login failed.\n");
    free(head);
}
