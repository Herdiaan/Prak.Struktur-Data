#include <iostream>
#include "nilaimahasiswa.h"
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "Nama         : " << m.nama << endl;
    cout << "NIM          : " << m.nim << endl;
    cout << "UTS          : " << m.uts << endl;
    cout << "UAS          : " << m.uas << endl;
    cout << "Tugas        : " << m.tugas << endl;
    cout << "Nilai Akhir  : " << m.nilaiAkhir << endl;
}