#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengecek apakah angka adalah bilangan prima
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Fungsi untuk mengecek apakah angka adalah palindrome
bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// Fungsi untuk menampilkan menu
void showMenu() {
    cout << "\n===== MENU VERIFIKASI KODE SANDI =====\n";
    cout << "1. Cek verifikasi kode sandi sebagai bilangan prima\n";
    cout << "2. Cek verifikasi kode sandi (Habis dibagi 2 dan 3, tapi tidak oleh 5)\n";
    cout << "3. Cek apakah kode sandi adalah bilangan palindrome\n";
    cout << "4. Keluar dari program\n";
    cout << "=======================================\n";
}

int main() {
    string username, password;
    int kodeSandi, pilihan;
    int attempts = 0;
    const int maxAttempts = 3;
    
    // Menu Login atau Keluar
    int loginChoice;
    cout << "1. Login\n2. Keluar\nPilihan: ";
    cin >> loginChoice;
    if (loginChoice != 1) {
        cout << "Program berhenti.\n";
        return 0;
    }
    
    // Proses login dengan batas 3 kali percobaan
    while (attempts < maxAttempts) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;
        
        if (username == "Ramadhan" && password == "2409106115") {
            cout << "Login berhasil!\n";
            break;
        } else {
            attempts++;
            cout << "Login gagal! Percobaan ke-" << attempts << " dari " << maxAttempts << "\n";
        }
    }
    
    if (attempts == maxAttempts) {
        cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }
    
    // Meminta input kode sandi dengan validasi
    do {
        cout << "Masukkan kode sandi (harus antara 100 dan 99999): ";
        cin >> kodeSandi;
        if (kodeSandi < 100 || kodeSandi > 99999) {
            cout << "Kode sandi tidak valid! Coba lagi.\n";
        }
    } while (kodeSandi < 100 || kodeSandi > 99999);
    
    do {
        showMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                if (isPrime(kodeSandi))
                    cout << "Kode sandi adalah bilangan prima.\n";
                else
                    cout << "Kode sandi BUKAN bilangan prima.\n";
                break;
            
            case 2:
                if (kodeSandi % 2 == 0 && kodeSandi % 3 == 0 && kodeSandi % 5 != 0)
                    cout << "Kode sandi valid sesuai aturan.\n";
                else
                    cout << "Kode sandi TIDAK valid sesuai aturan.\n";
                break;
            
            case 3:
                if (isPalindrome(kodeSandi))
                    cout << "Kode sandi adalah bilangan palindrome.\n";
                else
                    cout << "Kode sandi BUKAN bilangan palindrome.\n";
                break;
            
            case 4:
                cout << "Keluar dari program.\n";
                break;
                
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 4);
    
    return 0;
}
