#ifndef SINGLYLISH_H_INLCLUDED
#define SINGLYLISH_H_INLCLUDED
#include <iostream>
#define NIL NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct list {
    address first;
};

// Deklarasi Prosedur dan Fungsi Primitif
void createList(list &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void printInfo(list L);

#endif