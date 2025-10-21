#include "Playlist.h"

Playlist::Playlist() {
    head = nullptr;
}

Playlist::~Playlist() {
    Lagu* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Playlist::tambahDepan(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, head};
    head = baru;
    cout << "Lagu \"" << judul << "\" berhasil ditambahkan di awal playlist.\n";
}

void Playlist::tambahBelakang(string judul, string penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Lagu* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Lagu \"" << judul << "\" berhasil ditambahkan di akhir playlist.\n";
}

void Playlist::tambahSetelahKe3(string judul, string penyanyi, float durasi) {
    if (head == nullptr) {
        cout << "Playlist kosong. Tidak dapat menambahkan setelah lagu ke-3.\n";
        return;
    }

    Lagu* temp = head;
    int count = 1;

    while (temp != nullptr && count < 3) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Playlist kurang dari 3 lagu.\n";
    } else {
        Lagu* baru = new Lagu{judul, penyanyi, durasi, temp->next};
        temp->next = baru;
        cout << "Lagu \"" << judul << "\" berhasil ditambahkan setelah lagu ke-3.\n";
    }
}

void Playlist::hapusLagu(string judul) {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    if (head->judul == judul) {
        Lagu* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
        return;
    }

    Lagu* temp = head;
    while (temp->next != nullptr && temp->next->judul != judul) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Lagu \"" << judul << "\" tidak ditemukan.\n";
    } else {
        Lagu* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
    }
}

void Playlist::tampilkan() {
    if (head == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    Lagu* temp = head;
    int no = 1;
    cout << "\n=== Daftar Lagu dalam Playlist ===\n";
    while (temp != nullptr) {
        cout << no++ << ". Judul   : " << temp->judul << endl;
        cout << "   Penyanyi: " << temp->penyanyi << endl;
        cout << "   Durasi  : " << temp->durasi << " menit\n\n";
        temp = temp->next;
    }
}
