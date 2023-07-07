bool confirmChoice() {
    char choice;
    printf("Do you wish to continue? (Y/N): ");
    scanf(" %c", &choice);
    return (choice == 'Y' || choice == 'y');
}