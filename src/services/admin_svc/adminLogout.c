void adminLogout(struct Admin* admin) {
    admin->login_status = 0;
    FILE* file = fopen("../data/Logins.csv", "w");
    if (file != NULL) {
        fprintf(file, "Username,Password,OTP,LoginStatus\n");

        struct Admin* current = admin;
        while (current != NULL) {
            fprintf(file, "%s,%s,%d,%d\n", current->username, current->password, current->otp, current->login_status);
            current = current->next;
        }

        fclose(file);
        printf("Logout successful!\n");
        //printf("Login status updated in Logins.csv.\n");
    } else {
        printf("Failed to update login status in Logins.csv.\n");
    }
}
