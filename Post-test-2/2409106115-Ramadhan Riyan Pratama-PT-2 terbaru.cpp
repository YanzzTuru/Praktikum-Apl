#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100;

// Data sepatu
string sepatu[MAX];
int harga[MAX];
int stok[MAX];
int jumlahBarang = 10;

// Akun penjual
string usernamePenjual = "Ramadhan Riyan";
string passwordPenjual = "2409106115";

// Keranjang (belum digunakan di bagian ini)
string keranjang[MAX];
int jumlahKeranjang[MAX];
string pembeliKeranjang[MAX];
int hargaKeranjang[MAX];
int totalKeranjang = 0;

// Inisialisasi Data
int inisialisasiData() {
    sepatu[0] = "Nike Air Max"; harga[0] = 1200000; stok[0] = 10;
    sepatu[1] = "Adidas Ultraboost"; harga[1] = 1500000; stok[1] = 8;
    sepatu[2] = "Converse All Star"; harga[2] = 800000; stok[2] = 15;
    sepatu[3] = "Puma RS-X"; harga[3] = 1300000; stok[3] = 5;
    sepatu[4] = "Reebok Classic"; harga[4] = 900000; stok[4] = 12;
    sepatu[5] = "New Balance 574"; harga[5] = 1100000; stok[5] = 7;
    sepatu[6] = "Vans Old Skool"; harga[6] = 750000; stok[6] = 20;
    sepatu[7] = "Under Armour HOVR"; harga[7] = 1400000; stok[7] = 6;
    sepatu[8] = "Asics Gel-Kayano"; harga[8] = 1600000; stok[8] = 4;
    sepatu[9] = "Hoka One One Bondi"; harga[9] = 1700000; stok[9] = 3;
    return 1;
}

// Mengecek apakah string kosong atau hanya spasi
int isEmptyOrWhitespace(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isspace(str[i])) {
            return 0; // false
        }
    }
    return 1; // true
}

// Menampilkan stok
int tampilkanStok() {
    cout << "\n+-----------------------------------------------------------+\n";
    cout << "| No | Nama Sepatu           | Harga        | Stok         |\n";
    cout << "+-----------------------------------------------------------+\n";
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(21) << left << sepatu[i] << " | Rp"
             << setw(10) << harga[i] << " | "
             << setw(12) << stok[i] << "|\n";
    }
    cout << "+-----------------------------------------------------------+\n";
    return 1;
}

int loginPenjual() {
    string username, password;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts) {
        cout << "\n--- LOGIN PENJUAL ---\n";
        cout << "Masukan Username: ";
        getline(cin, username);
        cout << "Masukan Password: ";
        getline(cin, password);

        if (username == usernamePenjual && password == passwordPenjual) {
            return 1;
        } else {
            attempts++;
            cout << "Login gagal. Anda telah mencoba " << attempts << " kali.\n";
            if (attempts == maxAttempts) {
                cout << "Login gagal sebanyak 3 kali. Program berhenti.\n";
                return 0;
            }
        }
    }
    return 0;
}

// Menu penjual
int menuPenjual() {
    int pilihan;
    do {
        cout << "\n=== MENU PENJUAL ===\n";
        cout << "1. Lihat Stok\n2. Tambah Sepatu\n3. Ubah Harga\n4. Hapus Sepatu\n5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tampilkanStok();
        } else if (pilihan == 2) {
            cout << "Masukan Nama Sepatu: ";
            getline(cin, sepatu[jumlahBarang]);
            while (isEmptyOrWhitespace(sepatu[jumlahBarang]) == 1) {
                cout << "Nama sepatu tidak boleh kosong. Silakan coba lagi: ";
                getline(cin, sepatu[jumlahBarang]);
            }

            cout << "Masukan Harga: ";
            cin >> harga[jumlahBarang];
            while (harga[jumlahBarang] < 0) {
                cout << "Harga tidak boleh negatif. Masukkan harga valid: ";
                cin >> harga[jumlahBarang];
            }

            cout << "Masukan Jumlah Stok: ";
            cin >> stok[jumlahBarang];
            while (stok[jumlahBarang] < 0) {
                cout << "Stok tidak boleh negatif. Masukkan stok valid: ";
                cin >> stok[jumlahBarang];
            }
            cin.ignore();
            jumlahBarang++;
            cout << "Barang berhasil ditambahkan.\n";
        } else if (pilihan == 3) {
            tampilkanStok();
            int idx;
            cout << "Pilih nomor sepatu yang ingin diubah harganya: ";
            cin >> idx;
            idx--;
            cout << "Masukan Harga baru: ";
            cin >> harga[idx];
            while (harga[idx] < 0) {
                cout << "Harga tidak boleh negatif. Masukkan harga valid: ";
                cin >> harga[idx];
            }
            cin.ignore();
        } else if (pilihan == 4) {
            tampilkanStok();
            int idx;
            cout << "Pilih nomor sepatu yang ingin dihapus: ";
            cin >> idx;
            idx--;
            for (int i = idx; i < jumlahBarang - 1; i++) {
                sepatu[i] = sepatu[i + 1];
                harga[i] = harga[i + 1];
                stok[i] = stok[i + 1];
            }
            jumlahBarang--;
            cin.ignore();
            cout << "Sepatu berhasil dihapus.\n";
        }
    } while (pilihan != 5);
    return 1;
}

// Menu utama
int main() {
    inisialisasiData();
    int menu;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Login Penjual\n2. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;
        cin.ignore();
        if (menu == 1) {
            int loginBerhasil = loginPenjual();
            if (loginBerhasil == 1) {
                menuPenjual();
            } else {
                cout << "Program berhenti, terima kasih.\n";
                break;
            }
        } else if (menu == 2) {
            cout << "Terima kasih telah menggunakan program ini.\n";
        } else {
            cout << "Menu tidak valid.\n";
        }
    } while (menu != 2);
    return 0;
}
