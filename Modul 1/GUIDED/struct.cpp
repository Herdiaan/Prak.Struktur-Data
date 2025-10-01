#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() {
    Mahasiswa mhs;
    mhs.nama = "Herdian Abdillah Purnomo";
    mhs.NIM = "103112430048";

    cout << "Nama : " << mhs.nama << endl << "NIM : " << mhs.NIM;
}