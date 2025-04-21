#include <iostream>
#include <string>
#include "register.hpp"
#include "login.hpp"

using namespace std;

int main()
{
    int pilihan;

    do
    {
        cout << "\n+---------------------------------------+" << endl;
        cout << "|      Sistem Pemilihan Umum E-Vote     |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "| 1. Register                           |" << endl;
        cout << "| 2. Login                              |" << endl;
        cout << "|                                       |" << endl;
        cout << "| 0. Keluar                             |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "Pilih Opsi >>> ";
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
                cout << "\n+---------------------------------------+" << endl;
                cout << "| Terima kasih telah menggunakan Evote! |\n";
                cout << "+---------------------------------------+" << endl;
                break;
            default:
                cout << "\n+---------------------------------------+" << endl;
                cout << "|      Masukan pilihan yang sesuai      |";
                cout << "+---------------------------------------+" << endl;
        }

    } while (pilihan != 0);
    
}