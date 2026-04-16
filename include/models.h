#include <stdint.h>
#ifndef MODELS_H
#define MODELS_H

typedef enum { male = 0, female } gender;

typedef enum { intern = 0, junior, mid, senior, manager, ceo } jobTitle;

typedef struct Member {
    uint16_t id;
    char name[50];
    uint16_t age;
    gender gender;
    jobTitle jobTitle;
    double income;
    struct Member *next;
    struct Member *prev;
} Member;

typedef struct MembersList {
    Member *head;
    Member *tail;
    uint16_t count;
} MembersList;

#endif // MODELS_H
