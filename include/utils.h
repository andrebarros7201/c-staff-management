#ifndef UTILS_H
#define UTILS_H

#include "models.h"
const char *genderToString(gender gender);
const char *jobTitleToString(jobTitle jobTitle);
Member *findMember(MembersList *membersList, unsigned short id);

#endif // UTILS_H
