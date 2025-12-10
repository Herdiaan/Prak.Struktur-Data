#include "circularlist.h"
#include <iostream>

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    if (L.First != Nil) {
        L.First->prev = P;
    } else {
        L.Last = P;
    }
    L.First = P;
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec == Nil) {
        insertFirst(L, P);
        return;
    }
    if (Prec == L.Last) {
        insertLast(L, P);
        return;
    }
   
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First != Nil) {
        if (L.First == L.Last) {
            CreateList(L);
        } else {
            L.First = P->next;
            L.First->prev = Nil;
            P->next = Nil;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }
    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
        return;
    }
   
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.Last != Nil) {
        if (L.First == L.Last) {
            CreateList(L);
        } else {
            L.Last = P->prev;
            L.Last->next = Nil;
            P->prev = Nil;
        }
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List Mahasiswa Kosong." << endl;
        return;
    }
    cout << "--- Data Mahasiswa (Doubly Linked List) ---" << endl;
    while (P != Nil) {
        cout << "Nama: " << P->info.nama
             << ", NIM: " << P->info.nim
             << ", Kelamin: " << P->info.jenis_kelamin
             << ", IPK: " << P->info.ipk << endl;
        P = P->next;
    }
    cout << "-------------------------------------------" << endl;
}

address createData (string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    address P = alokasi(x);
    return P;
}