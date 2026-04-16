#include "menu.h"
#include "operations.h"
#include <stddef.h>
#include <stdio.h>

void menu() {
    int option;
    MembersList membersList = {NULL, NULL, 0};

    do {
        printf("\nMENU");
        printf("\n[0] Exit");
        printf("\n[1] See All Staff Members");
        printf("\n[2] See All Staff Members");
        printf("\n[3] Add Staff Member");
        printf("\n[4] Update Staff Member");
        printf("\n[5] Remove Staff Member");
        printf("\n[6] Save");
        printf("\n[7] Load");
        printf("\nOption: ");

        scanf_s("%d", &option);

        switch (option) {
        case 0:
            printf("Program exited");
            break;

        case 1:
            displayAllMembers(&membersList);
            break;

        case 2:
            int id;
            printf("ID: ");
            scanf_s("%d", &id);
            displayMember(&membersList, id);
            break;

        case 3:
            addMember();
            break;

        case 4:
            updateMember();
            break;

        case 5:
            removeMember();
            break;

        case 6:
            saveData();
            break;

        case 7:
            loadData();
            break;

        default:
            printf("Invalid option");
            break;
        }
    } while (option < 0 || option > 7);
}
