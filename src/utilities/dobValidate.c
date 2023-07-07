bool validateDateOfBirth(const char* dob) {
    // Check if the dob string has the correct length (10 characters)
    if (strlen(dob) != 10) {
        return false;
    }

    // Check if the dob string has the correct format (DD/MM/YYYY)
    if (dob[2] != '/' || dob[5] != '/') {
        return false;
    }

    // Extract day, month, and year from the dob string
    int day, month, year;
    if (sscanf(dob, "%2d/%2d/%4d", &day, &month, &year) != 3) {
        return false;
    }

    // Check if the day, month, and year values are within valid ranges
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2023) {
        return false;
    }

    // Additional validation rules can be added here if needed

    return true;
}