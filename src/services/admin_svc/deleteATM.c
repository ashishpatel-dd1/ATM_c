void deleteATM() {
    // Ask for criteria to display ATMs
    char state[MAX_STATE_LENGTH];
    char city[MAX_CITY_LENGTH];
    char type[10];

    printf("----------------------------\n");

    printf("Enter State: ");
    clearInputBuffer();
    fgets(state, sizeof(state), stdin);
    state[strcspn(state, "\n")] = '\0';  // Remove newline character

    printf("Enter City: ");
    fgets(city, sizeof(city), stdin);
    city[strcspn(city, "\n")] = '\0';  // Remove newline character

    printf("Enter Type (Urban or Rural): ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0';  // Remove newline character

    printf("---------------------------\n");

    // Display ATMs based on the provided criteria
    displayATM(state, city, type);

    // Ask for the ATM ID to delete
//     char atmID[50];
//     printf("Enter ATM ID to delete: ");
//     fgets(atmID, sizeof(atmID), stdin);
//     atmID[strcspn(atmID, "\n")] = '\0';  // Remove newline character

//     // Validate ATM ID
//     int found = 0;
//     FILE* inputFile = fopen(ATM_DETAILS_FILENAME, "r");
//     FILE* outputFile = fopen(DELETED_ATM_FILE, "a");
//     if (inputFile != NULL && outputFile != NULL) {
//         char line[256];
//         while (fgets(line, sizeof(line), inputFile)) {
//             char tempID[50];
//             sscanf(line, "%[^,]", tempID);

//             if (strcmp(tempID, atmID) == 0) {
//                 // ATM ID found, delete the ATM details
//                 found = 1;
//                 // Write the deleted ATM details to "DeletedATMs.csv" file
//                 fprintf(outputFile, "%s", line);
//             }
//         }

//         fclose(inputFile);
//         fclose(outputFile);

//         if (found) {
//             printf("ATM details deleted and moved to DeletedATMs.csv\n");
//         } else {
//             printf("ATM ID not found.\n");
//         }
//     } else {
//         printf("Failed to open files for deletion.\n");
//     }
// }
    char atmID[50];
    printf("Enter ATM ID to delete: ");
    fgets(atmID, sizeof(atmID), stdin);
    atmID[strcspn(atmID, "\n")] = '\0';  // Remove newline character

    // Validate ATM ID
    int found = 0;
    FILE* inputFile = fopen(ATM_DETAILS_FILENAME, "r");
    FILE* tempFile = fopen(ATM_DETAILS_TEMP_FILE, "w");
    if (inputFile != NULL && tempFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), inputFile)) {
            char tempID[50];
            sscanf(line, "%[^,]", tempID);

            if (strcmp(tempID, atmID) == 0) {
                // ATM ID found, skip deleting and move to "DeletedATMs.csv"
                found = 1;
                // Write the deleted ATM details to "DeletedATMs.csv" file
                FILE* deletedFile = fopen(DELETED_ATM_FILE, "a");
                if (deletedFile != NULL) {
                    long fileSize = ftell(deletedFile);
                    if (fileSize == 0) {
                        // File is empty, write the header
                        fprintf(deletedFile, "ATM ID,STATE,CITY,TYPE,ADDRESS\n");
                    }
                    fprintf(deletedFile, "%s", line);
                    fclose(deletedFile);
                } else {
                    printf("Failed to open DeletedATMs.csv for writing.\n");
                }
            } else {
                // Write the non-deleted ATM details to temp file
                fprintf(tempFile, "%s", line);
            }
        }

        fclose(inputFile);
        fclose(tempFile);

        if (found) {
            // Replace the original ATMs.csv file with temp file
            if (remove(ATM_DETAILS_FILENAME) == 0 && rename(ATM_DETAILS_TEMP_FILE, ATM_DETAILS_FILENAME) == 0) {
                printf("ATM details deleted successfully\n");
            } else {
                printf("Failed to delete ATM details\n");
            }
        } else {
            printf("ATM ID not found.\n");
            remove(ATM_DETAILS_TEMP_FILE);  // Remove temp file if no deletion occurred
        }
    } else {
        printf("Failed to open files for deletion.\n");
    }

    printf("-------------------------------------------------------------------\n");

}