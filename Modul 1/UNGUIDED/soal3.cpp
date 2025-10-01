#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Masukan: ";
    cin >> x;
    cout << "Keluaran:\n";

    for (int i = x; i >= 1; i--) {
        for (int jarak = 0; jarak < (x - i); jarak++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int jarak = 0; jarak < x; jarak++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}