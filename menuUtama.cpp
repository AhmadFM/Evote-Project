#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <ctime>
#include <windows.h>
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
        cout << "\n+---------------------------------------+" << endl;
        cout << "|             Menu Panitia              |\n";
        cout << "+---------------------------------------+" << endl;
        cout << "| 1. Ubah ketentuan voting              |\n";
        cout << "| 2. Verifikasi pasangan calon          |\n";
        cout << "| 3. Lihat gugatan/laporan              |\n";
        cout << "|                                       |\n";
        cout << "| 0. Kembali                            |\n";
        cout << "+---------------------------------------+" << endl;
        cout << "Pilih opsi >>> ";
        cin >> pilihan;
        system("cls");

        switch (pilihan)
        {
            case 1:
                ubahKetentuan();
                break;
            case 2:
                verifikasiKandidat();
                break;
            case 3:
                lihatLaporanGugatan();
                break;
            case 0:
                break;
            
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
        cout << "\n+---------------------------------------+" << endl;
        cout << "|             Menu Pemilih              |\n";
        cout << "+---------------------------------------+" << endl;
        cout << "| 1. Voting                             |\n";
        cout << "| 2. Cek hasil pemilu                   |\n";
        cout << "|                                       |\n";
        cout << "| 0. Keluar                             |\n";
        cout << "+---------------------------------------+" << endl;
        cout << "Pilih opsi >>> ";
        cin >> pilihan;
        system("cls");

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

        cout << "| Start: " << start_date << "\n";
        cout << "| End: " << end_date << "\n";
        cout << "| Now: " << now_date << "\n";

        switch (pilihan)
        {
            case 1:
                voting(start_date,end_date,now_date,username); //isi perameter waktu yang sesuai
                break;
            case 2:
                lihatJumlahSuara(now_date);
                break;
            case 0:
                break;
        }

    } while (pilihan != 0);
}