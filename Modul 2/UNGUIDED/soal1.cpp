#include <iostream>
#include <string>
using namespace std;


int main() {
    string nama[5];
    float nilai[5][3];
    float rata[5];
    int terbaik = 0;


    for (int i = 0; i < 5; i++) {
        cout << endl << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];


        float total = 0;
        for (int j = 0; j < 3; j++) {
            cout << "  Nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total = total + nilai[i][j];
        }
        rata[i] = total / 3;
    }


    for (int i = 1; i < 5; i++) {
        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }


    for (int i = 0; i < 5; i++) {
        cout << endl << "Nama: " << nama[i] << endl;
        cout << "Nilai: ";
          for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl << "Rata-rata: " << rata[i];
        if (i == terbaik)
            cout << "Terbaik";
        cout << endl;
    }


    cout << endl << "Mahasiswa terbaik: " << nama[terbaik]
         << " dengan rata-rata " << rata[terbaik] << endl;


    return 0;
}
