bool validateGender(const char* gender) {
    char lowercase[50];
    int i = 0;
    
    // Convert the input to lowercase
    while (gender[i]) {
        lowercase[i] = tolower(gender[i]);
        i++;
    }
    lowercase[i] = '\0';

    // Check if the lowercase gender is "male" or "female"
    if (strcmp(lowercase, "male") == 0 || strcmp(lowercase, "female") == 0) {
        return true;
    }
    
    return false;
}