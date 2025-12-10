#include "multilist.h"
#include <iostream>

using namespace std;

boolean ListEmpty (listinduk L) {
    return L.first == Nil;
}

boolean ListEmptyAnak (listanak L) {
    return L.first == Nil;
}

void CreateList (listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak (listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi (infotypeinduk X) {
    address P = new elemen_list_induk;
    if (P != Nil) {
        P->info = X;
        CreateListAnak(P->lanak);
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

address_anak alokasiAnak (infotypeanak X) {
    address_anak P = new elemen_list_anak;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi (address P) {
    delete P;
}

void dealokasiAnak (address_anak P) {
    delete P;
}

address findElm (listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

address_anak findElmAnak (listanak Lanak, infotypeanak X) {
    address_anak P = Lanak.first;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

boolean fFindElm (listinduk L, address P) {
    address current = L.first;
    while (current != Nil) {
        if (current == P) return true;
        current = current->next;
    }
    return false;
}

boolean fFindElmAnak (listanak Lanak, address_anak P) {
    address_anak current = Lanak.first;
    while (current != Nil) {
        if (current == P) return true;
        current = current->next;
    }
    return false;
}

address findBefore (listinduk L, address P) {
    if (P == L.first || P == Nil) return Nil;
    return P->prev;
}

address_anak findBeforeAnak (listanak Lanak, infotypeinduk X, address_anak P) {
    if (P == Lanak.first || P == Nil) return Nil;
    return P->prev;
}

void insertFirst (listinduk &L, address P) {
    P->next = L.first;
    if (!ListEmpty(L)) {
        L.first->prev = P;
    } else {
        L.last = P;
    }
    L.first = P;
    P->prev = Nil;
}

void insertAfter (listinduk &L, address P, address Prec) {
    if (Prec == L.last) {
        insertLast(L, P);
        return;
    }
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}

void insertLast (listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        P->next = Nil;
    }
}

void insertFirstAnak (listanak &L, address_anak P) {
    P->next = L.first;
    if (!ListEmptyAnak(L)) {
        L.first->prev = P;
    } else {
        L.last = P;
    }
    L.first = P;
    P->prev = Nil;
}

void insertAfterAnak (listanak &L, address_anak P, address_anak Prec) {
    if (Prec == L.last) {
        insertLastAnak(L, P);
        return;
    }
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}

void insertLastAnak (listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        P->next = Nil;
    }
}

void delFirst (listinduk &L, address &P) {
    P = L.first;
    if (!ListEmpty(L)) {
        if (L.first == L.last) {
            CreateList(L);
        } else {
            L.first = P->next;
            L.first->prev = Nil;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delLast (listinduk &L, address &P) {
    P = L.last;
    if (!ListEmpty(L)) {
        if (L.first == L.last) {
            CreateList(L);
        } else {
            L.last = P->prev;
            L.last->next = Nil;
            P->prev = Nil;
            P->next = Nil;
        }
    }
}

void delAfter (listinduk &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        if (P == L.last) {
            delLast(L, P);
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    } else {
        P = Nil;
    }
}

void delP (listinduk &L, infotypeinduk X) {
    address P = findElm(L, X);
    if (P != Nil) {
        address_anak c = P->lanak.first;
        while (c != Nil) {
            address_anak tempC = c;
            c = c->next;
            dealokasiAnak(tempC);
        }
       
        if (P == L.first) {
            delFirst(L, P);
        } else if (P == L.last) {
            delLast(L, P);
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
            P->next = Nil;
            P->prev = Nil;
        }
        dealokasi(P);
    }
}

void delFirstAnak (listanak &L, address_anak &P) {
    P = L.first;
    if (!ListEmptyAnak(L)) {
        if (L.first == L.last) {
            CreateListAnak(L);
        } else {
            L.first = P->next;
            L.first->prev = Nil;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delLastAnak (listanak &L, address_anak &P) {
    P = L.last;
    if (!ListEmptyAnak(L)) {
        if (L.first == L.last) {
            CreateListAnak(L);
        } else {
            L.last = P->prev;
            L.last->next = Nil;
            P->prev = Nil;
            P->next = Nil;
        }
    }
}

void delAfterAnak (listanak &L, address_anak &P, address_anak Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        if (P == L.last) {
            delLastAnak(L, P);
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    } else {
        P = Nil;
    }
}

void delPAnak (listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X);
    if (P != Nil) {
        if (P == L.first) {
            address_anak temp;
            delFirstAnak(L, temp);
            dealokasiAnak(temp);
        } else if (P == L.last) {
            address_anak temp;
            delLastAnak(L, temp);
            dealokasiAnak(temp);
        } else {
            P->prev->next = P->next;
            if (P->next != Nil) {
                 P->next->prev = P->prev;
            }
            dealokasiAnak(P);
        }
    }
}

void printInfoAnak (listanak Lanak) {
    address_anak P = Lanak.first;
    if (ListEmptyAnak(Lanak)) {
        cout << "Kosong";
        return;
    }
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << ", ";
        }
        P = P->next;
    }
}

void printInfo (listinduk L) {
    address P = L.first;
    if (ListEmpty(L)) {
        cout << "List Induk Kosong." << endl;
        return;
    }
    cout << "--- List Pegawai (Induk) ---" << endl;
    while (P != Nil) {
        cout << "Pegawai " << P->info << ": ";
        printInfoAnak(P->lanak);
        cout << endl;
        P = P->next;
    }
    cout << "----------------------------" << endl;
}

int nbList (listinduk L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

int nbListAnak (listanak Lanak) {
    int count = 0;
    address_anak P = Lanak.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void delAll (listinduk &L) {
    address P;
    while (!ListEmpty(L)) {
        delFirst(L, P);

        address_anak c = P->lanak.first;
        while (c != Nil) {
            address_anak tempC = c;
            c = c->next;
            dealokasiAnak(tempC);
        }
        dealokasi(P);
    }
    L.last = Nil;
}