#include "operations.h"
#include "models.h"
#include "utils.h"
#include <stdio.h>

void displayAllMembers(MembersList *membersList) {
    if (membersList->head == NULL) {
        printf("List is empty");
        return;
    }

    Member *curr = membersList->head;

    do {
        printf("\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
               "%s\tIncome: %f",
               curr->id, curr->name, curr->age, genderToString(curr->gender),
               jobTitleToString(curr->jobTitle), curr->income);
        curr = curr->next;
    } while (curr->next != NULL);
}

void displayMember(MembersList *membersList, unsigned int id) {
    Member *member = findMember(membersList, id);

    if (member == NULL) {
        printf("Member not found");
    }

    printf("\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
           "%s\tIncome: %f",
           member->id, member->name, member->age,
           genderToString(member->gender), jobTitleToString(member->jobTitle),
           member->income);
}
