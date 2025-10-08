#include <iostream>
using namespace std;

void tampilSegitiga(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah baris: ";
    cin >> n;

    tampilSegitiga(n);

    return 0;
}