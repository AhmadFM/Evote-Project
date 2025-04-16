#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
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
        cout << "1. Ubah ketentuan voting\n";
        cout << "2. Verifikasi pasangan calon\n";
        cout << "3. Lihat gugatan/laporan\n";
        cout << "0. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Ubah ketentuan voting\n";
                ubahKetentuan();
                break;
            case 2:
                cout << "Verifikasi pasangan calon\n";
                verifikasiKandidat();
                break;
            case 3:
                cout << "Lihat gugatan/laporan";
                lihatLaporanGugatan();
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

void menuPemilih(string username)
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

        time_t start_date;
        time_t end_date;
        time_t now_date = time(0);

        ifstream file("./ketentuan.txt");
        string textRead;
        int fileRow = 0;
        while (getline(file, textRead)) {
            if (fileRow == 0)
            {
                time_t convertedDate = (time_t)stoi(textRead);
                start_date = convertedDate;
            }
            else if (fileRow == 1)
            {
                time_t convertedDate = (time_t)stoi(textRead);
                end_date = convertedDate;
            }
            fileRow++;
        }

        cout << "Start: " << start_date << "\n";
        cout << "End: " << end_date << "\n";
        cout << "Now: " << now_date << "\n";

        switch (pilihan)
        {
            case 1:
                cout << "Voting\n";
                voting(start_date,end_date,now_date,username); //isi perameter waktu yang sesuai
                break;
            case 2:
                cout << "Cek hasil pemilu\n";
                lihatJumlahSuara(now_date);
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