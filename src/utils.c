#include "utils.h"
#include "models.h"

const char *genderToString(gender gender) {
    switch (gender) {
    case 0:
        return "Male";
        break;

    case 1:
        return "Female";
        break;

    default:
        return "NA";
        break;
    }
}

const char *jobTitleToString(jobTitle jobTitle) {
    switch (jobTitle) {
    case 0:
        return "Intern";
        break;

    case 1:
        return "Junior";
        break;

    case 2:
        return "Mid";
        break;

    case 3:
        return "Senior";
        break;

    case 4:
        return "Manager";
        break;

    case 5:
        return "CEO";
        break;

    default:
        return "NA";
        break;
    }
}

Member *findMember(MembersList *membersList, unsigned short id) {
    Member *head = membersList->head;
    if (head == NULL) {
        return NULL;
    }

    Member *curr = membersList->head;

    do {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    } while (curr->next != NULL);

    return NULL;
}
