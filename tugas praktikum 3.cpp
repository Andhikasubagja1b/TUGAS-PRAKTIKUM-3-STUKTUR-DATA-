#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_MHS 20

struct Nilai {
    float absen, tugas, uts, uas, akhir;
    char huruf;
};

struct Mahasiswa {
    string npm, nama;
    Nilai nilai;
} data[MAX_MHS];

int jumlah = 0;

char hitungHuruf(float n) { return (n > 80) ? 'A' : (n > 70) ? 'B' : (n > 60) ? 'C' : 'D'; }

void input() {
    if (jumlah >= MAX_MHS) { cout << "Data penuh!\n"; return; }

    cout << "============================\n";
    cout << "   Input Data Mahasiswa    \n";
    cout << "============================\n";
    cout << "NPM     : "; cin >> data[jumlah].npm;
    cin.ignore();
    cout << "Nama    : "; getline(cin, data[jumlah].nama);
    cout << "Absen   : "; cin >> data[jumlah].nilai.absen;
    cout << "Tugas   : "; cin >> data[jumlah].nilai.tugas;
    cout << "UTS     : "; cin >> data[jumlah].nilai.uts;
    cout << "UAS     : "; cin >> data[jumlah].nilai.uas;

    data[jumlah].nilai.akhir = 0.1 * data[jumlah].nilai.absen + 0.2 * data[jumlah].nilai.tugas + 0.3 * data[jumlah].nilai.uts + 0.4 * data[jumlah].nilai.uas;
    data[jumlah].nilai.huruf = hitungHuruf(data[jumlah].nilai.akhir);
    jumlah++;

    cout << "Data berhasil ditambahkan!\n";
}

void tampil() {
    cout << "\n=================================================\n";
    cout << "NPM              Nama           Akhir  Huruf\n";
    cout << "=================================================\n";
    for (int i = 0; i < jumlah; i++) {
        cout << data[i].npm << "   " << data[i].nama << "   "
             << fixed << setprecision(2) << data[i].nilai.akhir << "   "
             <<    data[i].nilai.huruf << "\n";
    }
}

void edit() {
    string npm;
    cout << "Masukkan NPM yang akan diedit: "; cin >> npm;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].npm == npm) {
            cout << "Absen   : "; cin >> data[i].nilai.absen;
            cout << "Tugas   : "; cin >> data[i].nilai.tugas;
            cout << "UTS     : "; cin >> data[i].nilai.uts;
            cout << "UAS     : "; cin >> data[i].nilai.uas;

            data[i].nilai.akhir = 0.1 * data[i].nilai.absen + 0.2 * data[i].nilai.tugas + 0.3 * data[i].nilai.uts + 0.4 * data[i].nilai.uas;
            data[i].nilai.huruf =   hitungHuruf(data[i].nilai.akhir);
            cout << "Data berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}

void hapus() {
    string npm;
    cout << "Masukkan NPM yang akan dihapus: "; cin >> npm;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].npm == npm) {
            for (int j = i; j < jumlah - 1; j++) data[j] = data[j + 1];
            jumlah--;
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}

int main() {
    int p;
    do {
        cout << "\n============================\n";
        cout << "   MENU DATA MAHASISWA    \n";
        cout << "============================\n";
        cout << "1. Input Data\n2. Tampilkan Data\n3. Edit Data\n4. Hapus Data\n5. Keluar\n";
        cout << "Pilih: "; cin >> p;

        switch (p) {
            case 1: input(); break;
            case 2: tampil(); break;
            case 3: edit(); break;
            case 4: hapus(); break;
        }
    } while (p != 5);
    cout << "Terima kasih telah menggunakan program ini!\n";
}
