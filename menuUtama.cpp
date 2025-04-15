#include <iostream>
#include <string>
#include "menuUtama.hpp"

using namespace std;

void menuPanitia()
{
    int pilihan;

    do
    {
        cout << "\n ======= Menu Panitia =======\n";
        cout << "1. Atur ketentuan pemilu\n";
        cout << "2. Verifikasi pasangan calon\n";
        cout << "3. Edit data pemilih\n";
        cout << "4. Verifikasi gugatan/laporan\n";
        cout << "0. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Atur ketentuan pemilu\n";
                break;
            case 2:
                cout << "Verifikasi pasangan calon\n";
                break;
            case 3: 
                cout << "Edit data pemilih\n";
                break;
            case 4:
                cout << "Verifikasi gugatan/laporan";
                break;
            case 0:
                cout << "Kembali ke menu utama\n";
            
        }
    } while (pilihan != 0);
    
}

void menuTimSukses()
{
    int pilihan;

    do
    {
        cout << "\n ====== Menu Tim Sukses ======\n";
        cout << "1. Form pengajuan pasangan calon\n";
        cout << "2. Edit Informasi pasangan calon\n";
        cout << "3. Form gugatan\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1: 
                cout << "Form pengajuan pasangan calon\n";
                break;
            case 2:
                cout << "Edit informasi pasangan calon\n";
                break;
            case 3:
                cout << "Form gugatan\n";
                break;
            case 0:
                cout << "Kembali ke menu utama\n";

        }
    } while (pilihan != 0);
    
}

void menuPemilih()
{
    int pilihan;

    do
    {
        cout << "\n ======= Menu Pemilih =======\n";
        cout << "1. Voting\n";
        cout << "2. Cek hasil pemilu\n";
        cout << "3. Lapor kecurangan\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Voting\n";
                break;
            case 2:
                cout << "Cek hasil pemilu\n";
                break;
            case 3:
                cout << "Lapor kecurangan\n";
                break;
            case 0:
                cout << "Kembali ke menu utama\n";

        }

    } while (pilihan != 0);
    
}