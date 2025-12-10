#include "circularlist.h"
#include "circularlist.cpp"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1 = Nil;
    address P2 = Nil;
    address P_del = Nil;
    infotype x;

    CreateList(L);
    cout << "### Pengujian Doubly Linked List Mahasiswa ###" << endl;
    cout << "--- Coba Insert First, Last, dan After ---" << endl;

    P1 = createData("Danu", "04", 'L', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'L', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'L', 3.71);
    x.nim = "04";
    P2 = findElm(L, x);
    if (P2 != Nil) {
        insertAfter(L, P2, P1);
    }

    P1 = createData("Ali", "01", 'L', 3.3);
    insertFirst(L, P1);
   
    P1 = createData("Gita", "07", 'P', 3.75);
    insertLast(L, P1);
    x.nim = "07";
    P2 = findElm(L, x);
    P1 = createData("Cindi", "03", 'P', 3.5);
    if (P2 != Nil) {
        insertAfter(L, P2, P1);
    }
   
    x.nim = "02";
    P2 = findElm(L, x);
    P1 = createData("Hilmi", "08", 'L', 3.3);
    if (P2 != Nil) {
        insertAfter(L, P2, P1);
    }
   
    x.nim = "04";
    P2 = findElm(L, x);
    P1 = createData("Eli", "05", 'P', 3.4);
    if (P2 != Nil) {
        insertAfter(L, P2, P1);
    }

    cout << "\n[Setelah Semua Insert]" << endl;
    printInfo(L);
   
    deleteFirst(L, P_del);
    if (P_del != Nil) dealokasi(P_del);
    cout << "\n[Setelah Delete First (Ali)]" << endl;
    printInfo(L);

    deleteLast(L, P_del);
    if (P_del != Nil) dealokasi(P_del);
    cout << "\n[Setelah Delete Last (Cindi)]" << endl;
    printInfo(L);
   
    x.nim = "04";
    P2 = findElm(L, x);
    if (P2 != Nil) {
        deleteAfter(L, P2, P_del);
        if (P_del != Nil) dealokasi(P_del);
    }
    cout << "\n[Setelah Delete After (Eli)]" << endl;
    printInfo(L);

    return 0;
}