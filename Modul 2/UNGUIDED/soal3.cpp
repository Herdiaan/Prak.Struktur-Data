#include <iostream>
using namespace std;

float hitungRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return (float) total / n;
}

void cariNilai(int arr[], int n, int &maks, int &min) {
    maks = arr[0];
    min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) maks = arr[i];
        if (arr[i] < min) min = arr[i];
    }
}

int main() {
    int N;
    cout << "Masukkan jumlah siswa: ";
    cin >> N;
     int nilai[N];
    cout << "Masukkan nilai ujian untuk " << N << " siswa:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    float rata = hitungRata(nilai, N);
    int maks, min;
    cariNilai(nilai, N, maks, min);

    cout << "\n=== HASIL ===" << endl;
    cout << "Rata-rata kelas : " << rata << endl;
    cout << "Nilai tertinggi : " << maks << endl;
    cout << "Nilai terendah  : " << min << endl;

    return 0;
}