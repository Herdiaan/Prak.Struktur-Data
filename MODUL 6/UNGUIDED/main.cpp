#include "Doublylist.h"
#include "Doublylist.cpp"


int main() {
    List L;
    createList(L);
    int pilihan;
    do {
        cout << "\n===== MENU DOUBLY LINKED LIST =====\n";
        cout << "1. Tambah Data Kendaraan\n";
        cout << "2. Lihat Semua Data\n";
        cout << "3. Cari Data Kendaraan\n";
        cout << "4. Hapus Data Kendaraan\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            infotype x;
            cout << "\nMasukkan Nomor Polisi : ";
            cin >> x.nopol;
            cout << "Masukkan Warna        : ";
            cin >> x.warna;
            cout << "Masukkan Tahun Buat   : ";
            cin >> x.thnBuat;
            insertLast(L, alokasi(x));
            cout << "Data berhasil ditambahkan!\n";
        }

        else if (pilihan == 2) {
            printInfo(L);
        }

        else if (pilihan == 3) {
            string nopol;
            cout << "\nMasukkan nomor polisi yang dicari: ";
            cin >> nopol;
            address P = findElm(L, nopol);
            if (P != Nil) {
                cout << "\nData ditemukan:\n";
                cout << "Nopol  : " << P->info.nopol << endl;
                cout << "Warna  : " << P->info.warna << endl;
                cout << "Tahun  : " << P->info.thnBuat << endl;
            } else {
                cout << "\nData dengan nopol " << nopol << " tidak ditemukan.\n";
            }
        }

        else if (pilihan == 4) {
            string nopol;
            cout << "\nMasukkan nomor polisi yang akan dihapus: ";
            cin >> nopol;
            address P = findElm(L, nopol);
            if (P != Nil) {
                if (P == L.first)
                    deleteFirst(L, P);
                else if (P == L.last)
                    deleteLast(L, P);
                else
                    deleteAfter(P->prev, P);
                dealokasi(P);
                cout << "Data berhasil dihapus.\n";
            } else {
                cout << "Data tidak ditemukan.\n";
            }
        }

    } while (pilihan != 0);

    cout << "\nProgram selesai. Terima kasih!\n";
    return 0;
}