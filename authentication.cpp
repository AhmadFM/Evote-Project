#include <iostream>
using namespace std;

// int isPemilih() {}

// int isPanitia() {}

// int isTimSes() {}

int verifLogin(string accountName, string password) {
    // cek panjang password untuk membedakan jenis akun
    if (password.length() == 16) {
        // account = pemilih
        return 1;
    } else if (password.length() >= 8 && password.length() <= 12) {
        // account = panitia / tim sukses
        return 2;
    } else {
        cout << "Pastikan password yang anda masukan benar." << endl;
        return 3;
    }
    // apakah data akun sesuai dengan ketentan yang ada pada panitia
}

void verifPaslon() {
    // cek timsesnya apakah sama atau tidak -> sama = gagal
    // apakah data paslon sesuai dengan ketentuan yang ada pada panitia
}

// timses menyalonkan kandidat

int main() {
    return 0;
}