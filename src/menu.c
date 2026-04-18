#include "menu.h"
#include "operations.h"
#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void menu() {
    system("cls");
    int option;
    int id = 0;
    MembersList membersList = {NULL, NULL, 0};
    loadData(&membersList, &id);

    do {
        printf("\n\n\nMENU");
        printf("\n[0] Exit");
        printf("\n[1] See All Staff Members");
        printf("\n[2] See Staff Member");
        printf("\n[3] Add Staff Member");
        printf("\n[4] Update Staff Member");
        printf("\n[5] Remove Staff Member");
        printf("\n[6] Save");
        printf("\nOption: ");

        scanf_s("%d", &option);

        switch (option) {
        case 0:
            system("cls");
            printf("Program exited");
            break;

        case 1:
            system("cls");
            displayAllMembers(&membersList);
            break;

        case 2: {
            system("cls");
            int id;
            printf("ID: ");
            scanf_s("%d", &id);
            displayMember(&membersList, id);
            break;
        }

        case 3:
            system("cls");
            Member *temp = createMember();
            if (temp == NULL) {
                printf("Failed to create member");
                break;
            }
            temp->id = ++id;
            addMember(&membersList, temp);
            break;

        case 4: {
            int id;
            printf("ID: ");
            scanf_s("%d", &id);
            system("cls");
            updateMember(&membersList, id);
            break;
        }

        case 5: {
            system("cls");
            int id;
            printf("ID: ");
            scanf_s("%d", &id);
            removeMember(&membersList, id);
            break;
        }

        case 6:
            system("cls");
            saveData(&membersList, &id);
            break;

        default:
            printf("Invalid option");
            break;
        }
    } while (option != 0);
}
