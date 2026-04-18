#ifndef UTILS_H
#define UTILS_H

#include "models.h"
#include <stdint.h>
const char *genderToString(gender gender);
const char *jobTitleToString(jobTitle jobTitle);
Member *findMember(MembersList *membersList, unsigned id);
Member *createMember();

#endif // UTILS_H
