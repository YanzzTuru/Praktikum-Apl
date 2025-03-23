#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 100;

// Struct data sepatu
struct Sepatu {
    string nama;
    int harga;
    int stok;
};

// Array of struct
Sepatu daftarSepatu[MAX];
int jumlahSepatu = 10;

// Akun penjual
string namaPenjual = "Ramadhan Riyan";
string nimPenjual = "2409106115";

// Fungsi cek nama kosong/spasi
int isKosongAtauSpasi(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        if (!isspace(teks[i])) {
            return 0; // Tidak kosong
        }
    }
    return 1; // Kosong/spasi saja
}

// Inisialisasi data sepatu
int inisialisasiData() {
    string namaDefault[10] = {
        "Nike Air Max", "Adidas Ultraboost", "Converse All Star", "Puma RS-X",
        "Reebok Classic", "New Balance 574", "Vans Old Skool", "Under Armour HOVR",
        "Asics Gel-Kayano", "Hoka One One Bondi"
    };
    int hargaDefault[10] = {1200000, 1500000, 800000, 1300000, 900000, 1100000, 750000, 1400000, 1600000, 1700000};
    int stokDefault[10] = {10, 8, 15, 5, 12, 7, 20, 6, 4, 3};

    for (int i = 0; i < 10; i++) {
        daftarSepatu[i].nama = namaDefault[i];
        daftarSepatu[i].harga = hargaDefault[i];
        daftarSepatu[i].stok = stokDefault[i];
    }
    return 1;
}

// Tampilkan semua sepatu
int tampilkanSepatu() {
    cout << "\n+-----------------------------------------------------------+\n";
    cout << "| No | Nama Sepatu           | Harga        | Stok         |\n";
    cout << "+-----------------------------------------------------------+\n";
    for (int i = 0; i < jumlahSepatu; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(21) << left << daftarSepatu[i].nama << " | Rp"
             << setw(10) << daftarSepatu[i].harga << " | "
             << setw(12) << daftarSepatu[i].stok << "|\n";
    }
    cout << "+-----------------------------------------------------------+\n";
    return 1;
}

// Login penjual
int loginPenjual() {
    string inputNama, inputNIM;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\n=== LOGIN PENJUAL ===\n";
        cout << "Masukkan Nama: ";
        getline(cin, inputNama);
        cout << "Masukkan NIM : ";
        getline(cin, inputNIM);

        if (inputNama == namaPenjual && inputNIM == nimPenjual) {
            cout << "Login berhasil!\n";
            return 1;
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan ke-" << percobaan << " dari 3.\n";
        }
    }
    cout << "Gagal login sebanyak 3 kali. Program dihentikan.\n";
    return 0;
}

// Tambah data sepatu
int tambahSepatu() {
    cin.ignore();
    string nama;
    int harga, stok;

    // Validasi nama
    do {
        cout << "Masukkan Nama Sepatu: ";
        getline(cin, nama);
        if (isKosongAtauSpasi(nama) == 1) {
            cout << "Nama sepatu tidak boleh kosong atau hanya spasi!\n";
        }
    } while (isKosongAtauSpasi(nama) == 1);

    // Validasi harga
    do {
        cout << "Masukkan Harga       : ";
        cin >> harga;
        if (harga < 0) {
            cout << "Harga tidak boleh negatif!\n";
        }
    } while (harga < 0);

    // Validasi stok
    do {
        cout << "Masukkan Stok        : ";
        cin >> stok;
        if (stok < 0) {
            cout << "Stok tidak boleh negatif!\n";
        }
    } while (stok < 0);

    daftarSepatu[jumlahSepatu].nama = nama;
    daftarSepatu[jumlahSepatu].harga = harga;
    daftarSepatu[jumlahSepatu].stok = stok;
    jumlahSepatu++;

    cout << "Data sepatu berhasil ditambahkan.\n";
    return 1;
}

// Ubah data sepatu
int ubahSepatu() {
    tampilkanSepatu();
    int pilih;
    cout << "Pilih nomor sepatu yang ingin diubah: ";
    cin >> pilih;
    pilih--;

    if (pilih >= 0 && pilih < jumlahSepatu) {
        cin.ignore();
        string nama;
        int harga, stok;

        // Validasi nama
        do {
            cout << "Masukkan Nama Baru  : ";
            getline(cin, nama);
            if (isKosongAtauSpasi(nama) == 1) {
                cout << "Nama tidak boleh kosong!\n";
            }
        } while (isKosongAtauSpasi(nama) == 1);

        // Validasi harga
        do {
            cout << "Masukkan Harga Baru : ";
            cin >> harga;
            if (harga < 0) {
                cout << "Harga tidak boleh negatif!\n";
            }
        } while (harga < 0);

        // Validasi stok
        do {
            cout << "Masukkan Stok Baru  : ";
            cin >> stok;
            if (stok < 0) {
                cout << "Stok tidak boleh negatif!\n";
            }
        } while (stok < 0);

        daftarSepatu[pilih].nama = nama;
        daftarSepatu[pilih].harga = harga;
        daftarSepatu[pilih].stok = stok;

        cout << "Data berhasil diubah.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
    return 1;
}

// Hapus data sepatu
int hapusSepatu() {
    tampilkanSepatu();
    int pilih;
    cout << "Pilih nomor sepatu yang ingin dihapus: ";
    cin >> pilih;
    pilih--;

    if (pilih >= 0 && pilih < jumlahSepatu) {
        for (int i = pilih; i < jumlahSepatu - 1; i++) {
            daftarSepatu[i] = daftarSepatu[i + 1];
        }
        jumlahSepatu--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Nomor tidak valid.\n";
    }
    return 1;
}

// Menu penjual setelah login berhasil
int menuPenjual() {
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

        if (pilih == 1) {
            tampilkanSepatu();
        } else if (pilih == 2) {
            tambahSepatu();
        } else if (pilih == 3) {
            ubahSepatu();
        } else if (pilih == 4) {
            hapusSepatu();
        } else if (pilih == 5) {
            cout << "Logout berhasil.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);
    return 1;
}

// Menu utama program
int main() {
    inisialisasiData();
    int menu;

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Login Penjual\n";
        cout << "2. Keluar Program\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            if (loginPenjual() == 1) {
                menuPenjual();
            } else {
                return 0;
            }
        } else if (menu == 2) {
            cout << "Terima kasih telah menggunakan program ini.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (menu != 2);

    return 0;
}
