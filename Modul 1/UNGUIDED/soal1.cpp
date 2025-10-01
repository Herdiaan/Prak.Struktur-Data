#include <iostream>
using namespace std;

int main() {
    float x, y;

    cout << "Masukan sebuah bilangan:";
    cin >> x;
    cout << "Masukan bilangan kedua:";
    cin >> y;

    float perkalian = x * y;
    float pembagian = x / y;
    float penjumlahan = x + y;
    float pengurangan = x - y;

    cout << "\nHasil Penjumlahan: " << x + y << endl;
    cout << "Hasil Pengurangan: " << x - y << endl;
    cout << "Hasil Perkalian  : " << x * y << endl;
 
    if (y != 0) {
        cout << "Hasil Pembagian  : " << x / y << endl;
    } else {
        cout << "Tidak bisa dibagi dengan nol!" << endl;
    }

    return 0;
    cout << "\nHasil Penjumlahan: " << x + y << endl;
    cout << "Hasil Pengurangan: " << x - y << endl;
}
 

