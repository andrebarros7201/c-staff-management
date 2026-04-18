#include "menu.h"
#include "operations.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    int option;
    int id = 0;
    MembersList membersList = {NULL, NULL, 0};

    do {
        printf("\n\n\nMENU");
        printf("\n[0] Exit");
        printf("\n[1] See All Staff Members");
        printf("\n[2] See Staff Member");
        printf("\n[3] Add Staff Member");
        printf("\n[4] Update Staff Member");
        printf("\n[5] Remove Staff Member");
        printf("\n[6] Save");
        printf("\n[7] Load");
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
            char name[50];
            printf("\nName: ");
            scanf("%s", name);

            int age;
            printf("\nAge: ");
            scanf_s("%d", &age);

            gender gender;
            printf("\n\nGender\n\nMale: 1\nFemale: 2\nOption: ");
            scanf_s("%d", &gender);

            jobTitle jobTitle;
            printf("\n\nJob Title\n\nIntern: 1\nJunior: 2\nMid: 3\nSenior: "
                   "4\nManager: 5\nCEO: 6\n\nOption: ");
            scanf_s("%d", &jobTitle);

            double income;
            printf("\nIncome: ");
            scanf_s("%lf", &income);

            Member *member = malloc(sizeof(Member));

            member->id = ++id;
            strcpy_s(member->name, sizeof(name), name);
            member->age = age;
            member->gender = gender;
            member->jobTitle = jobTitle;
            member->income = income;
            member->next = NULL;
            member->prev = NULL;

            addMember(&membersList, member);
            break;

        case 4:
            system("cls");
            // TODO
            // updateMember();
            break;

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
            saveData(&membersList);
            break;

        case 7:
            system("cls");
            // TODO
            // loadData();
            break;

        default:
            printf("Invalid option");
            break;
        }
    } while (option != 0);
}
