#include <iostream>
#include <string>
#include "authentication.cpp"
#include "menuUtama.cpp"
#include "register.cpp"
#include "login.cpp"

using namespace std;

int main()
{
    int pilihan;

    do
    {
        cout << "\n ================== Sistem Pemilihan Umum E-Vote ==================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Keluar\n";
        cout << "Pilih Opsi: \n";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 0:
                cout << "Terima kasih telah meluangkan waktu Anda\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
        }

    } while (pilihan != 0);
    
}