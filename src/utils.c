#include "utils.h"
#include "models.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *genderToString(gender gender) {
    switch (gender) {
    case 1:
        return "Male";
        break;

    case 2:
        return "Female";
        break;

    default:
        return "NA";
        break;
    }
}

const char *jobTitleToString(jobTitle jobTitle) {
    switch (jobTitle) {
    case 1:
        return "Intern";
        break;

    case 2:
        return "Junior";
        break;

    case 3:
        return "Mid";
        break;

    case 4:
        return "Senior";
        break;

    case 5:
        return "Manager";
        break;

    case 6:
        return "CEO";
        break;

    default:
        return "NA";
        break;
    }
}

Member *findMember(MembersList *membersList, unsigned id) {
    Member *head = membersList->head;
    if (head == NULL) {
        return NULL;
    }

    Member *curr = membersList->head;

    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

Member *createMember() {

    char name[50];
    printf("\nName: ");
    scanf("%49s", name);

    int age;
    printf("\nAge: ");
    scanf_s("%d", &age);

    gender gender;
    printf("\n\nGender\n\nMale: 1\nFemale: 2\n\nOption: ");
    scanf_s("%d", &gender);

    jobTitle jobTitle;
    printf("\n\nJob Title\n\nIntern: 1\nJunior: 2\nMid: 3\nSenior: "
           "4\nManager: 5\nCEO: 6\n\nOption: ");
    scanf_s("%d", &jobTitle);

    double income;
    printf("\nIncome: ");
    scanf_s("%lf", &income);

    Member *member = malloc(sizeof(Member));
    if (member == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    strcpy_s(member->name, sizeof(name), name);
    member->age = age;
    member->gender = gender;
    member->jobTitle = jobTitle;
    member->income = income;
    member->next = NULL;
    member->prev = NULL;

    return member;
}
