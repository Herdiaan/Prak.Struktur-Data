#include <iostream>
#include <cstdlib>
#include "singlyList.h"
#include "singlyList.cpp"

using namespace std;

int main()
{
    list L;
    address P; // Cukup satu pointer untuk digunakan berulang kali

    createList(L);

    cout << "Mengisi list menggunaka interLast..." << endl;

    // Mengisi list sesuai urutan
    P = alokasi(9);
    insertLast(L, P);

    P = alokasi(12);
    insertLast(L, P);

    P = alokasi(8);
    insertLast(L, P);

    P = alokasi(0);
    insertLast(L, P);

    P = alokasi(2);
    insertLast(L, P);

    cout << "Isi list sekarang adalah: " ;
    printInfo(L);

    system("pause");
    return 0;
}