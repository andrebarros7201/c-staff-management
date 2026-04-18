#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "models.h"

void displayAllMembers(MembersList *membersList);
void displayMember(MembersList *membersList, unsigned int id);
void addMember(MembersList *membersList, Member *member);
void updateMember(MembersList *membersList, unsigned int id);
void removeMember(MembersList *membersList, unsigned int id);
void saveData(MembersList *membersList, int *id);
void loadData(MembersList *membersList, int *id);

#endif // OPERATIONS_H
