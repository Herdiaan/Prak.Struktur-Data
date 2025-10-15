#include <iostream>
#include "nilaimahasiswa.h"
#include "nilaimahasiswa.cpp"

using namespace std;

int main() {
    Mahasiswa data[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "NIM   : ";
        getline(cin, data[i].nim);
        cout << "UTS   : ";
        cin >> data[i].uts;
        cout << "UAS   : ";
        cin >> data[i].uas;
        cout << "Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        tampilMahasiswa(data[i]);
        cout << endl;
    }

    return 0;
}