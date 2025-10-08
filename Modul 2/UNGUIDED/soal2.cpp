#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah bilangan: ";
    cin >> N;

    int *arr = new int[N];
    int *p = arr;

    cout << "Masukkan " << N << " bilangan:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> *(p + i);
    }

    int jumlah = 0;
    int maks = *p;
    int min = *p;

    for (int i = 0; i < N; i++) {
        jumlah = jumlah + *(p + i);
        if (*(p + i) > maks) maks = *(p + i);
        if (*(p + i) < min) min = *(p + i);
    }

    cout << endl;
    cout << "Jumlah bilangan = " << jumlah << endl;
    cout << "Nilai maksimum  = " << maks << endl;
    cout << "Nilai minimum   = " << min << endl;

    delete[] arr;
    return 0;
}