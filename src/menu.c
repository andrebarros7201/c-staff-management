#include "menu.h"
#include <stddef.h>
#include <stdio.h>

void menu() {
    int option;

    do {
        printf("\nMENU");
        printf("\n[0] Exit");
        printf("\n[1] See All Staff Members");
        printf("\n[2] Add Staff Member");
        printf("\n[3] Remove Staff Member");
        printf("\n[4] Save");
        printf("\n[5] Load");
        printf("\nOption: ");

        scanf_s("%d", &option);

        switch (option) {
        case 0:
            printf("Program exited");
            break;

        default:
            printf("Invalid choice");
            break;
        }
    } while (option < 0 || option > 5);
}
