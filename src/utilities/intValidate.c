bool validateInteger(const char* str) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}