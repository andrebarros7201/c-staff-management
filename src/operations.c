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
        return;
    }

    printf("\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
           "%s\tIncome: %f",
           member->id, member->name, member->age,
           genderToString(member->gender), jobTitleToString(member->jobTitle),
           member->income);
}

void addMember(MembersList *membersList, Member *member) {
    membersList->count++;

    // Initialize members list
    if (membersList->head) {
        membersList->head = member;
        membersList->tail = member;
        return;
    };

    member->prev = membersList->tail;
    membersList->tail->next = member;
    membersList->tail = member;
    return;
}

void removeMember(MembersList *membersList, unsigned int id) {
    Member *member = findMember(membersList, id);

    if (member == NULL) {
        printf("Member not found");
        return;
    }

    membersList->count--;

    // Is head
    if (member->prev == NULL) {
        membersList->head = member->next;
        membersList->head->prev = NULL;
        return;
    }

    // is tail
    if (member->next == NULL) {
        membersList->tail = member->prev;
        membersList->tail->next = NULL;
        return;
    }

    member->next->prev = member->prev;
    member->prev->next = member->next;
    printf("Member deleted");
    return;
}

void saveData(MembersList *membersList) {
    if (membersList->head == NULL) {
        return;
    }

    FILE *file;
    file = fopen("data.txt", "w");

    Member *curr = membersList->head;
    do {
        fprintf(file,
                "\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
                "%s\tIncome: %f",
                curr->id, curr->name, curr->age, genderToString(curr->gender),
                jobTitleToString(curr->jobTitle), curr->income);
        curr = curr->next;
    } while (curr->next != NULL);

    fclose(file);
}
