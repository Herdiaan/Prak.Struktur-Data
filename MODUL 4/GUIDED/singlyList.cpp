#include "singlyList.h"

void createList(list &L) {
    L.first = NIL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(list &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(list &L, address P) {
    if (L.first == NIL) {
        // Jika list kosong, interLast sama dengan insertFirst
        insertFirst(L, P);
    } else {
        // Jika list tidak kosong, cari element terakhir
        address Last = L.first;
        while (Last->next != NIL) {
            Last = Last->next;
        }
        // Sambungkan elemen terakhir dengan elemen terbaru (p)
        Last->next = P;
    }
}

void printInfo(list L) {
    address P = L.first;
    if (P == NIL) {
        std::cout << "List kosong" << std::endl;
    } else {
        while (P != NIL) {
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
    
}
