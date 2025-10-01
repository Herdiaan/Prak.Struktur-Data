#include <iostream>
#include <string>
using namespace std;

struct mahasiswa
{
    string nama;
    string NIM;
};

int main() {
    mahasiswa mhs;
    
    cout << "Nama : ";
    getline(cin, mhs.nama);
    cout << "NIM : ";
    cin >> mhs.NIM;

    cout << "Nama : " << mhs.nama << endl << "NIM : " << mhs.NIM;
}
