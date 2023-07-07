#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define LOGINS_FILENAME "../data/Logins.csv"

struct Admin {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int otp;
    int login_status;
    struct Admin* next;
};

struct Admin* createAdminNode() {
    struct Admin* node = (struct Admin*)malloc(sizeof(struct Admin));
    if (node != NULL) {
        node->next = NULL;
    }
    return node;
}