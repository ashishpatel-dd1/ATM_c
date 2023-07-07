bool validateAccountType(const char* accountType) {
    char lowercase[50];
    int i = 0;
    
    // Convert the input to lowercase
    while (accountType[i]) {
        lowercase[i] = tolower(accountType[i]);
        i++;
    }
    lowercase[i] = '\0';

    // Check if the lowercase gender is "male" or "female"
    if (strcmp(lowercase, "salary") == 0 || strcmp(lowercase, "savings") == 0 || strcmp(lowercase, "current") == 0) {
        return true;
    }
    
    return false;
}