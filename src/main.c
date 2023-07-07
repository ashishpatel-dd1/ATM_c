#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


#include"../headers/admin.h"
#include"../headers/atmDetails.h"
#include"../headers/customer.h"
#include"../headers/prototype.h"


#include"../src/services/admin_svc/adminLogin.c"
#include"../src/services/admin_svc/adminLogout.c"
#include"../src/services/admin_svc/addATM.c"
#include"../src/services/admin_svc/deleteATM.c"
#include"../src/services/admin_svc/addAccount.c"
#include"../src/services/admin_svc/clearCheque.c"
#include"../src/services/admin_svc/closeAccount.c"
#include"../src/services/admin_svc/viewTransactions.c"
#include"../src/services/admin_svc/viewStatement.c"


#include"../src/services/menu_svc/adminMenu.c"
#include"../src/services/menu_svc/mainMenu.c"


#include"../src/utilities/intValidate.c"
#include"../src/utilities/confirmChoice.c"
#include"../src/utilities/alphaValidate.c"
#include"../src/utilities/clearBuffer.c"
#include"../src/utilities/displayATM.c"
#include"../src/utilities/dobValidate.c"
#include"../src/utilities/accountTypeValidate.c"
#include"../src/utilities/genderValidate.c"
#include"../src/utilities/panValidate.c"



int main()
{
    mainMenu();
    return 0;
}
