bool confirmChoice();
bool validateInteger(const char* str);
bool validateAlphabetsOnly(const char* str);
void clearInputBuffer();
bool validateDateOfBirth(const char* dob);
bool validateGender(const char* accountType);
bool validatePanCard(const char* panCardNo);
bool validateAccountType(const char* accountType);


void changePassword(struct Admin* admin, int isFirstTimeLogin);
void updateLoginStatus(struct Admin* admin);
int generateOTP();
void adminLogin();
void adminLogout(struct Admin* admin);

void addAccount();
void closeAccount();
int isAccountExists(unsigned int accountNumber);
int isAccountClosed(unsigned int accountNumber);
void verifyAndClearCheck(struct Admin* admin);
void generateStatement(struct Admin* admin);

void generateUniqueNumbers(CUSTOMER* customer);
void viewTransactionsOfATM();


void addATM();
void deleteATM();
void displayATM(const char* state, const char* city, const char* type);     


void mainMenu();
void adminMenu(struct Admin* admin);

