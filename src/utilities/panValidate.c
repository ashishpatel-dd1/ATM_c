bool validatePanCard(const char* panCardNo) {
    // Check if the PAN Card number is exactly 10 characters
    if (strlen(panCardNo) != 10) {
        return false;
    }

    // Check if the first five characters are uppercase letters
    for (int i = 0; i < 5; i++) {
        if (!isupper(panCardNo[i])) {
            return false;
        }
    }

    // Check if the next four characters are digits
    for (int i = 5; i < 9; i++) {
        if (!isdigit(panCardNo[i])) {
            return false;
        }
    }

    // Check if the last character is an uppercase letter
    if (!isupper(panCardNo[9])) {
        return false;
    }

    return true;
}