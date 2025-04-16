#include <iostream>
#include <string>
#include <ctime>
#include "menuUtama.hpp"
#include "pemilih.hpp"
#include "panitia.hpp"
#include "timses.hpp"

using namespace std;

void menuPanitia()
{
    int pilihan;

    do
    {
        cout << "\n ======= Menu Panitia =======\n";
        cout << "1. Verifikasi pasangan calon\n";
        cout << "2. Edit data pemilih\n";
        cout << "3. Verifikasi gugatan/laporan\n";
        cout << "0. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Verifikasi pasangan calon\n";
                verifikasiKandidat();
                break;
            case 2: 
                cout << "Edit data pemilih\n";
                break;
            case 3:
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

    tampilkanMenu();
    main_timses();
    
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
        time_t waktu = time(0);

        switch (pilihan)
        {
            case 1:
                cout << "Voting\n";
                voting(waktu,waktu,waktu); //isi perameter waktu yang sesuai
                break;
                case 2:
                cout << "Cek hasil pemilu\n";
                lihatJumlahSuara(waktu);
                break;
            case 3:
                cout << "Lapor kecurangan\n";
                laporKecurangan();
                break;
            case 0:
                cout << "Kembali ke menu utama\n";

        }

    } while (pilihan != 0);
    
}