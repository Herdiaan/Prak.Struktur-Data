#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <stddef.h>
#define Nil NULL

typedef int infotypeanak;
typedef int infotypeinduk;
typedef int boolean;
#define true 1
#define false 0

struct elemen_list_anak;
struct elemen_list_induk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

boolean ListEmpty (listinduk L);
boolean ListEmptyAnak (listanak L);

void CreateList (listinduk &L);
void CreateListAnak (listanak &L);

address alokasi (infotypeinduk X);
address_anak alokasiAnak (infotypeanak X);
void dealokasi (address P);
void dealokasiAnak (address_anak P);

address findElm (listinduk L, infotypeinduk X);
address_anak findElmAnak (listanak Lanak, infotypeanak X);
boolean fFindElm (listinduk L, address P);
boolean fFindElmAnak (listanak Lanak, address_anak P);
address findBefore (listinduk L, address P);
address_anak findBeforeAnak (listanak Lanak, infotypeinduk X, address_anak P);

void insertFirst (listinduk &L, address P);
void insertAfter (listinduk &L, address P, address Prec);
void insertLast (listinduk &L, address P);
void insertFirstAnak (listanak &L, address_anak P);
void insertAfterAnak (listanak &L, address_anak P, address_anak Prec);
void insertLastAnak (listanak &L, address_anak P);

void delFirst (listinduk &L, address &P);
void delLast (listinduk &L, address &P);
void delAfter (listinduk &L, address &P, address Prec);
void delP (listinduk &L, infotypeinduk X);

void delFirstAnak (listanak &L, address_anak &P);
void delLastAnak (listanak &L, address_anak &P);
void delAfterAnak (listanak &L, address_anak &P, address_anak Prec);
void delPAnak (listanak &L, infotypeanak X);

void printInfo (listinduk L);
void printInfoAnak (listanak Lanak);
int nbList (listinduk L);
int nbListAnak (listanak Lanak);

void delAll (listinduk &L);

#endif