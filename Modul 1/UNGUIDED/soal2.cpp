#include <iostream>
using namespace std;

string ubahTulisan(int n) {
    if (n == 0) return "nol";
    if (n == 1) return "satu";
    if (n == 2) return "dua";
    if (n == 3) return "tiga";
    if (n == 4) return "empat";
    if (n == 5) return "lima";
    if (n == 6) return "enam";
    if (n == 7) return "tujuh";
    if (n == 8) return "delapan";
    if (n == 9) return "sembilan";
    if (n == 10) return "sepuluh";
    if (n == 11) return "sebelas";
    if (n == 100) return "seratus";
    if (n < 20) return ubahTulisan(n % 10) + " belas";
    if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = ubahTulisan(puluh) + " puluh";
        if (sisa != 0) hasil += " " + ubahTulisan(sisa);
        return hasil;
    }
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan" << endl;
    } else {
        cout << angka << " : " << ubahTulisan(angka) << endl;
    }

    return 0;
}



