#include <iostream>
#include <string>
#include "login.cpp"
#include "register.cpp"
#include "menuUtama.cpp"
using namespace std;

int main()
{
    int pilihan;
    user* loggedInUser;
    // loggedInUser = loginUser();

    // do
    // {
    //     cout << "\n======= Sistem Pemilihan Umum E-Vote =======\n";
    //     cout << "1. Register\n";
    //     cout << "2. Login\n";
    //     cout << "0. Keluar\n";
    //     cout << "Pilih Opsi: \n";      
    //     cin >> pilihan;

    //     switch (pilihan)
    //     {
    //         case 1:
    //             registerUser();
    //             break;
    //         case 2:
    //             loggedInUser = loginUser();
    //             if (loggedInUser != NULL)
    //             {
    //                 menuUtama(loggedInUser);
    //             }
    //             break;
    //         case 0:
    //             cout << "Terima kasih telah meluangkan waktu Anda\n";
    //             return 0;
    //         default:
    //             cout << "Pilihan tidak valid\n";
    //     }
    //     } while (pilihan !=3);
        return 0;

    }