#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
// #include <vector>
#include "panitia.hpp"

using namespace std;

struct paslon
{
    string nama_tim;
    string ketua;
    string wakil;
    string visi;
    string misi;
    paslon* next;
};


paslon* readKandidat()
{
    ifstream file("./calon_kandidat.csv");
    
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return NULL;
    }

    paslon* headKandidat = NULL;
    paslon* prevKandidat = NULL;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        int cellNumber = 0;

        paslon* dataKandidat = new paslon();
        
        while (getline(ss, cell, ',')) {
            if (cellNumber == 0)
            {
                dataKandidat->nama_tim = cell;
            }
            else if (cellNumber == 1)
            {
                dataKandidat->ketua = cell;
            }
            else if (cellNumber == 2)
            {
                dataKandidat->wakil = cell;   
            }
            else if (cellNumber == 3)
            {
                dataKandidat->visi = cell;   
            }
            else if (cellNumber == 4)
            {
                dataKandidat->misi = cell;   
            }
            cellNumber++;
        }

        if (prevKandidat != NULL)
        {
            prevKandidat->next = dataKandidat;
        }
        if (headKandidat == NULL)
        {
            headKandidat = dataKandidat;
        }
        prevKandidat = dataKandidat;
    }

    return headKandidat;
}

bool writeKandidat(paslon* headKandidat)
{
    ofstream file("./confirmedKandidat.csv");
    
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return false;
    }

    paslon* currentKandidat = headKandidat;

    while (currentKandidat != NULL)
    {
        file 
            << currentKandidat->nama_tim << "," 
            << currentKandidat->ketua << ","
            << currentKandidat->wakil << ","
            << currentKandidat->visi << ","
            << currentKandidat->misi << "\n";

        currentKandidat = currentKandidat->next;
    }

    file.close();

    return true;
}

struct laporanGugatan
{
    string penggugat;
    string tergugat;
    string teks;
    laporanGugatan* next;
};

laporanGugatan* readLaporanGugatan()
{
    ifstream file("./laporan_gugatan.csv");
    
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return NULL;
    }

    laporanGugatan* headLaporan = NULL;
    laporanGugatan* prevLaporan = NULL;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        int cellNumber = 0;

        laporanGugatan* dataLaporan = new laporanGugatan();
        
        while (getline(ss, cell, ',')) {
            if (cellNumber == 0)
            {
                dataLaporan->penggugat = cell;
            }
            else if (cellNumber == 1)
            {
                dataLaporan->tergugat = cell;
            }
            else if (cellNumber == 2)
            {
                dataLaporan->teks = cell;   
            }
            cellNumber++;
        }

        if (prevLaporan != NULL)
        {
            prevLaporan->next = dataLaporan;
        }
        if (headLaporan == NULL)
        {
            headLaporan = dataLaporan;
        }
        prevLaporan = dataLaporan;
    }

    return headLaporan;
}

// std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
//     std::vector<std::vector<std::string>> data;
//     std::ifstream file(filename);
    
//     if (!file.is_open()) {
//         std::cerr << "Failed to open file: " << filename << std::endl;
//         return data;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         std::vector<std::string> row;
//         std::stringstream ss(line);
//         std::string cell;

//         while (std::getline(ss, cell, ',')) {
//             row.push_back(cell);
//         }

//         data.push_back(row);
//     }

//     file.close();
//     return data;
// }

void ubahKetentuan()
{
    cout << "\n ======= Ubah Ketentuan Voting =======\n\n";

    cout << "1. Kapan mulai voting?\n";
    struct tm start_date;
    {
        int year = 0;
        int month = 0;
        int day = 0;
        int hour = 0;
        int minute = 0;
        int seconds = 0;

        while (true) {
            cout << "Tahun: ";
            cin >> year; 
            if (year > 1901) break;
        }
        while (true)
        {
            cout << "Bulan: ";
            cin >> month; 
            if (month > 0 && month < 13) break;
        }
        while (true)
        {
            cout << "Tanggal: ";
            cin >> day;
            if (day > 0 && day < 32) break;
        }
        while (true)
        {
            cout << "Jam: ";
            cin >> hour; 
            if (hour > -1 && hour < 24) break;
        }
        while (true)
        {
            cout << "Menit: ";
            cin >> minute; 
            if (minute > -1 && minute < 60) break;
        }
        while (true)
        {
            cout << "Detik: ";
            cin >> seconds;
            if (seconds > -1 && seconds < 60) break;
        }

        start_date.tm_year = year - 1900;
        start_date.tm_mon = month - 1;
        start_date.tm_mday = day;
        start_date.tm_hour = hour; 
        start_date.tm_min = minute; 
        start_date.tm_sec = seconds;
        start_date.tm_isdst = -1;
    }

    cout << "2. Kapan selesai voting?\n";
    struct tm end_date;
    {
        int year = 0;
        int month = 0;
        int day = 0;
        int hour = 0;
        int minute = 0;
        int seconds = 0;

        while (true) {
            cout << "Tahun: ";
            cin >> year; 
            if (year > 1901) break;
        }
        while (true)
        {
            cout << "Bulan: ";
            cin >> month; 
            if (month > 0 && month < 13) break;
        }
        while (true)
        {
            cout << "Tanggal: ";
            cin >> day;
            if (day > 0 && day < 32) break;
        }
        while (true)
        {
            cout << "Jam: ";
            cin >> hour; 
            if (hour > -1 && hour < 24) break;
        }
        while (true)
        {
            cout << "Menit: ";
            cin >> minute; 
            if (minute > -1 && minute < 60) break;
        }
        while (true)
        {
            cout << "Detik: ";
            cin >> seconds;
            if (seconds > -1 && seconds < 60) break;
        }
    
        end_date.tm_year = year - 1900;
        end_date.tm_mon = month - 1;
        end_date.tm_mday = day;
        end_date.tm_hour = hour; 
        end_date.tm_min = minute; 
        end_date.tm_sec = seconds;
        end_date.tm_isdst = -1;
    }

    ofstream file("./ketentuan.txt");
    
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return;
    }

    time_t start_timestamp = mktime(&start_date);
    time_t end_timestamp = mktime(&end_date);

    file << start_timestamp << "\n" << end_timestamp;


}

void verifikasiKandidat()
{
    cout << "\n ======= Verifikasi Kandidat Paslon =======\n\n";

    paslon* headKandidatConfirmed = NULL;
    paslon* currentKandidatConfirmed = NULL;

    int noUrut = 1;

    paslon* headKandidat = readKandidat();
    if (headKandidat == NULL)
    {
        return;
    }

    paslon* currentKandidat = headKandidat;
    while (currentKandidat != NULL)
    {
        cout << "No Urut: " << noUrut << "\n";
        cout << "Nama Tim Sukses: " << currentKandidat->nama_tim << "\n";
        cout << "Ketua: " << currentKandidat->ketua << "\n";
        cout << "Wakil: " << currentKandidat->wakil << "\n";
        cout << "Visi: " << currentKandidat->visi << "\n";
        cout << "Misi: " << currentKandidat->misi << "\n";

        while (true)
        {
            cout << "Apakah diterima? (Ya/Tidak) ";
            string konfirmasi = "";
            cin >> konfirmasi;
            if (konfirmasi == "Ya")
            {
                cout << "Kandidat diterima!\n\n";

                paslon* kandidatConfirmed = new paslon {
                    .nama_tim = currentKandidat->nama_tim,
                    .ketua = currentKandidat->ketua,
                    .wakil = currentKandidat->wakil,
                    .visi = currentKandidat->visi,
                    .misi = currentKandidat->misi
                };

                if (headKandidatConfirmed == NULL)
                {
                    headKandidatConfirmed = kandidatConfirmed;
                }
                
                if (currentKandidatConfirmed != NULL)
                {
                    currentKandidatConfirmed->next = kandidatConfirmed;
                }
                currentKandidatConfirmed = kandidatConfirmed;

                break;
            }
            else if (konfirmasi == "Tidak")
            {
                cout << "Kandidat ditolak!\n\n";
                break;
            }
        }

        currentKandidat = currentKandidat->next;
        noUrut++;
    }

    writeKandidat(headKandidatConfirmed);
}

void lihatLaporanGugatan()
{
    cout << "\n ======= Lihat Laporan Gugatan =======\n\n";

    laporanGugatan* headLaporan = readLaporanGugatan();
    laporanGugatan* currentLaporan = headLaporan;

    int noUrut = 1;
    while (currentLaporan != NULL)
    {
        cout << noUrut << ". \n";
        cout << "Penggugat: " << currentLaporan->penggugat << "\n";
        cout << "Tergugat: " << currentLaporan->tergugat << "\n";
        cout << "Teks: " << currentLaporan->teks << "\n\n";

        noUrut++;
        currentLaporan = currentLaporan->next;
    }
}