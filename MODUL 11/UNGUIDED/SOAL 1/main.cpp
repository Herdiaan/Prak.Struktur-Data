#include "multilist.h"
#include "multilist.cpp"
#include <iostream>

using namespace std;

int main() {
    listinduk PegawaiList;
    CreateList(PegawaiList);

    cout << "### Pengujian Multi Linked List Pegawai-Anak ###" << endl;

    address p1 = alokasi(10);
    address p2 = alokasi(20);
    address p3 = alokasi(30);

    insertFirst(PegawaiList, p1);
    insertLast(PegawaiList, p3);
    insertAfter(PegawaiList, p2, p1);

    cout << "\n[Step 1: Insert Induk]" << endl;
    printInfo(PegawaiList);
    cout << "Jumlah Total Pegawai: " << nbList(PegawaiList) << endl;

    address_anak a1 = alokasiAnak(101);
    address_anak a2 = alokasiAnak(102);
    address_anak a3 = alokasiAnak(103);

    insertFirstAnak(p1->lanak, a1);
    insertAfterAnak(p1->lanak, a2, a1);
    insertLastAnak(p1->lanak, a3);
   
    address_anak c1 = alokasiAnak(301);
    insertLastAnak(p3->lanak, c1);

    cout << "\n[Step 2: Insert Anak]" << endl;
    printInfo(PegawaiList);
    cout << "Jumlah Anak Pegawai 10: " << nbListAnak(p1->lanak) << endl;

    cout << "\n[Step 3: Delete Anak 102 dari Pegawai 10]" << endl;
    delPAnak(p1->lanak, 102);
    printInfo(PegawaiList);
   
    cout << "\n[Step 4: Delete Pegawai 20]" << endl;
    delP(PegawaiList, 20);
    printInfo(PegawaiList);

    address foundP = findElm(PegawaiList, 30);
    cout << "\n[Step 5: Pencarian]" << endl;
    if (foundP != Nil) {
        cout << "Pegawai 30 ditemukan." << endl;
    }
    address_anak foundA = findElmAnak(foundP->lanak, 301);
    if (foundA != Nil) {
        cout << "Anak 301 dari Pegawai 30 ditemukan." << endl;
    }

    cout << "\n[Step 6: Delete All]" << endl;
    delAll(PegawaiList);
    printInfo(PegawaiList);
    cout << "Jumlah Total Pegawai: " << nbList(PegawaiList) << endl;

    return 0;
}