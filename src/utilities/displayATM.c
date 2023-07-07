void displayATM(const char* state, const char* city, const char* type) {
    // Read "ATMs.csv" file
    FILE* file = fopen(ATM_DETAILS_FILENAME, "r");
    if (file == NULL) {
        printf("Failed to open ATMs.csv for reading.\n");
        return;
    }

    // Display ATMs matching the criteria
    char line[256];
    int found = 0;  // Variable to keep track of whether any ATMs are found or not
    while (fgets(line, sizeof(line), file)) {
        // Parse the line to extract ATM details
        char atmID[MAX_ATM_ID_LENGTH];
        char atmState[MAX_STATE_LENGTH];
        char atmCity[MAX_CITY_LENGTH];
        char atmType[10];
        char atmAddress[MAX_ADDRESS_LENGTH];

        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^\n]", atmID, atmState, atmCity, atmType, atmAddress);

        // Check if the ATM matches the provided criteria
        if (strcmp(atmState, state) == 0 && strcmp(atmCity, city) == 0 && strcmp(atmType, type) == 0) {
            printf("ATM ID:  %s\n", atmID);
            printf("State:   %s\n", atmState);
            printf("City:    %s\n", atmCity);
            printf("Type:    %s\n", atmType);
            printf("Address: %s\n", atmAddress);
            printf("---------------------------\n");
            found = 1;  // At least one ATM is found
        }
    }

    if (!found) {
        printf("No ATMs found matching the criteria.\n");
    }

    fclose(file);
}
