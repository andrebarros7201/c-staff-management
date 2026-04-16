#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "models.h"

void displayAllMembers(MembersList *membersList);
void displayMember(MembersList *membersList, unsigned int id);
void addMember();
void updateMember();
void removeMember();
void saveData();
void loadData();

#endif // OPERATIONS_H
