#include <stdio.h>
//#include "./sqlite_db/sqlite3.h"
#include "../common/pesel_check.c"

int main(){
        int valid_pesel[] = {0, 5, 2, 1, 1, 5, 1, 0, 7, 5, 7};

    printf("Pesel check result: %011llu\n", check_pesel(valid_pesel));
    



    return 0;}
