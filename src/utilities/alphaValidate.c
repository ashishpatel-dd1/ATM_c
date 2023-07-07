bool validateAlphabetsOnly(const char* str) {
    int i = 0;
    while (str[i]) {
        if (!isalpha(str[i]) && !isspace(str[i]))
            return false;
        i++;
    }
    return true;
}

// && !isspace(str[i])