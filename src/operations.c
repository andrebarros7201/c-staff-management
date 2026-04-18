#include "operations.h"
#include "models.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayAllMembers(MembersList *membersList) {
    if (membersList->head == NULL) {
        printf("List is empty");
        return;
    }

    Member *curr = membersList->head;

    while (curr) {
        printf("\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
               "%s\tIncome: %.2f $",
               curr->id, curr->name, curr->age, genderToString(curr->gender),
               jobTitleToString(curr->jobTitle), curr->income);
        curr = curr->next;
    };
}

void displayMember(MembersList *membersList, unsigned int id) {
    Member *member = findMember(membersList, id);

    if (member == NULL) {
        printf("Member not found");
        return;
    }

    printf("\nID: %d\tName: %s\tAge: %d\tGender: %s\tJob Title: "
           "%s\tIncome: %.2f€",
           member->id, member->name, member->age,
           genderToString(member->gender), jobTitleToString(member->jobTitle),
           member->income);
}

void addMember(MembersList *membersList, Member *member) {
    if (member == NULL) {
        return;
    }

    ++membersList->count;

    // Initialize members list
    if (membersList->head == NULL) {
        membersList->head = member;
        membersList->tail = member;
        return;
    };

    member->prev = membersList->tail;
    membersList->tail->next = member;
    membersList->tail = member;
    return;
}

void updateMember(MembersList *membersList, unsigned int id) {
    if (membersList->head == NULL) {
        printf("Member not found");
        return;
    }

    Member *member = findMember(membersList, id);
    if (member == NULL) {
        printf("Member not found");
        return;
    }
    Member *temp = createMember();
    if (temp == NULL) {
        printf("Failed to update member");
        return;
    }

    // Dont change id
    strcpy(member->name, temp->name);
    member->age = temp->age;
    member->gender = temp->gender;
    member->jobTitle = temp->jobTitle;
    member->income = temp->income;
    free(temp);
    printf("Successfully updated member");
}

void removeMember(MembersList *membersList, unsigned int id) {
    Member *member = findMember(membersList, id);

    if (member == NULL) {
        printf("Member not found");
        return;
    }

    --membersList->count;

    // Is head
    if (member->prev == NULL) {
        membersList->head = member->next;
        if (membersList->head != NULL)
            membersList->head->prev = NULL;
        else // Was the only member
            membersList->tail = NULL;
        free(member);
        return;
    }

    // is tail
    if (member->next == NULL) {
        membersList->tail = member->prev;
        membersList->tail->next = NULL;
        free(member);
        return;
    }

    member->next->prev = member->prev;
    member->prev->next = member->next;
    printf("Member deleted");
    free(member);
    return;
}

void saveData(MembersList *membersList, int *id) {
    if (membersList->head == NULL) {
        return;
    }

    FILE *fp = fopen("data.txt", "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(id, sizeof(int), 1, fp);

    Member *curr = membersList->head;
    while (curr != NULL) {
        fwrite(curr, sizeof(Member), 1, fp);
        curr = curr->next;
    };

    fclose(fp);
    printf("Saved successfully");
}

void loadData(MembersList *membersList, int *id) {
    FILE *fp = fopen("data.txt", "rb");

    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fread(id, sizeof(int), 1, fp);
    Member temp;
    while (fread(&temp, sizeof(Member), 1, fp) == 1) {
        Member *member = malloc(sizeof(Member));
        if (member == NULL) {
            printf("Memory allocation failed");
            break;
        }
        *member = temp;
        member->prev = NULL;
        member->next = NULL;
        addMember(membersList, member);
    }

    fclose(fp);
    printf("Loaded successfully");
}
