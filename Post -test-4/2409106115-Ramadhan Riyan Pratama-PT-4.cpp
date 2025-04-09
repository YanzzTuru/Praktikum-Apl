#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

// Struct
struct Sepatu {
    string nama;
    int harga;
    int stok;
};

// Array of struct
Sepatu daftarSepatu[MAX];
int jumlahSepatu = 10;

// Akun Penjual
string namaPenjual = "Ramadhan Riyan";
string nimPenjual = "2409106115";

// Fungsi Cek Nama Kosong
int isKosongAtauSpasi(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        if (!isspace(teks[i])) return 0;
    }
    return 1;
}

// Fungsi Overloading untuk validasi input integer
int validasiInput(string label, int& nilai) {
    do {
        cout << label;
        cin >> nilai;
        if (nilai < 0) {
            cout << "Input tidak boleh negatif!\n";
        }
    } while (nilai < 0);
    return 1;
}

// Prosedur inisialisasi data
void inisialisasiData(Sepatu daftar[], int& jumlah) {
    string namaDefault[10] = {
        "Nike Air Max", "Adidas Ultraboost", "Converse All Star", "Puma RS-X",
        "Reebok Classic", "New Balance 574", "Vans Old Skool", "Under Armour HOVR",
        "Asics Gel-Kayano", "Hoka One One Bondi"
    };
    int hargaDefault[10] = {1200000, 1500000, 800000, 1300000, 900000, 1100000, 750000, 1400000, 1600000, 1700000};
    int stokDefault[10] = {10, 8, 15, 5, 12, 7, 20, 6, 4, 3};

    for (int i = 0; i < 10; i++) {
        daftar[i].nama = namaDefault[i];
        daftar[i].harga = hargaDefault[i];
        daftar[i].stok = stokDefault[i];
    }
    jumlah = 10;
}

// Prosedur tampilkan data
void tampilkanSepatu(Sepatu daftar[], int jumlah) {
    cout << "\n+-----------------------------------------------------------+\n";
    cout << "| No | Nama Sepatu           | Harga        | Stok         |\n";
    cout << "+-----------------------------------------------------------+\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(21) << left << daftar[i].nama << " | Rp"
             << setw(10) << daftar[i].harga << " | "
             << setw(12) << daftar[i].stok << "|\n";
    }
    cout << "+-----------------------------------------------------------+\n";
}

// Fungsi login penjual
int loginPenjual(string namaBenar, string nimBenar) {
    string inputNama, inputNIM;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\n=== LOGIN PENJUAL ===\n";
        cout << "Masukkan Nama: ";
        getline(cin, inputNama);
        cout << "Masukkan NIM : ";
        getline(cin, inputNIM);

        if (inputNama == namaBenar && inputNIM == nimBenar) {
            cout << "Login berhasil!\n";
            return 1;
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan ke-" << percobaan << " dari 3.\n";
        }
    }
    return 0;
}

// Prosedur tambah sepatu
void tambahSepatu(Sepatu daftar[], int& jumlah) {
    cin.ignore();
    string nama;
    int harga, stok;

    do {
        cout << "Masukkan Nama Sepatu: ";
        getline(cin, nama);
        if (isKosongAtauSpasi(nama)) {
            cout << "Nama sepatu tidak boleh kosong!\n";
        }
    } while (isKosongAtauSpasi(nama));

    validasiInput("Masukkan Harga       : ", harga);
    validasiInput("Masukkan Stok        : ", stok);

    daftar[jumlah].nama = nama;
    daftar[jumlah].harga = harga;
    daftar[jumlah].stok = stok;
    jumlah++;

    cout << "Data sepatu berhasil ditambahkan.\n";
}

// Prosedur ubah data sepatu
void ubahSepatu(Sepatu daftar[], int jumlah) {
    tampilkanSepatu(daftar, jumlah);
    int pilih;
    validasiInput("Pilih nomor sepatu yang ingin diubah: ", pilih);
    pilih--;

    if (pilih >= 0 && pilih < jumlah) {
        cin.ignore();
        string nama;
        int harga, stok;

        do {
            cout << "Masukkan Nama Baru  : ";
            getline(cin, nama);
            if (isKosongAtauSpasi(nama)) {
                cout << "Nama tidak boleh kosong!\n";
            }
        } while (isKosongAtauSpasi(nama));

        validasiInput("Masukkan Harga Baru : ", harga);
        validasiInput("Masukkan Stok Baru  : ", stok);

        daftar[pilih].nama = nama;
        daftar[pilih].harga = harga;
        daftar[pilih].stok = stok;

        cout << "Data berhasil diubah.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

// Prosedur hapus sepatu
void hapusSepatu(Sepatu daftar[], int& jumlah) {
    tampilkanSepatu(daftar, jumlah);
    int pilih;
    validasiInput("Pilih nomor sepatu yang ingin dihapus: ", pilih);
    pilih--;

    if (pilih >= 0 && pilih < jumlah) {
        for (int i = pilih; i < jumlah - 1; i++) {
            daftar[i] = daftar[i + 1];
        }
        jumlah--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
}

// Prosedur Menu Penjual
void menuPenjual(Sepatu daftar[], int& jumlah) {
    int pilih;
    do {
        cout << "\n=== MENU PENJUAL ===\n";
        cout << "1. Lihat Data Sepatu\n";
        cout << "2. Tambah Data Sepatu\n";
        cout << "3. Ubah Data Sepatu\n";
        cout << "4. Hapus Data Sepatu\n";
        cout << "5. Logout ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) tampilkanSepatu(daftar, jumlah);
        else if (pilih == 2) tambahSepatu(daftar, jumlah);
        else if (pilih == 3) ubahSepatu(daftar, jumlah);
        else if (pilih == 4) hapusSepatu(daftar, jumlah);
        else if (pilih != 5) cout << "Pilihan tidak valid.\n";
    } while (pilih != 5);
}

// Fungsi rekursif exit program
void exitProgram(int count) {
    if (count == 0) {
        cout << "Terima kasih telah menggunakan program ini.\n";
        return;
    }
    exitProgram(count - 1);
}

// Main
int main() {
    inisialisasiData(daftarSepatu, jumlahSepatu);
    int menu;

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Login Penjual\n";
        cout << "2. Keluar Program\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            if (loginPenjual(namaPenjual, nimPenjual)) {
                menuPenjual(daftarSepatu, jumlahSepatu);
            } else {
                return 0;
            }
        } else if (menu == 2) {
            exitProgram(1);
        } else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (menu != 2);

    return 0;
}
