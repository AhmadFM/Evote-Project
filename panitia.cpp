#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
// #include <vector>
#include "panitia.hpp"

using namespace std;

struct paslon
{
    int no_urut;
    string ketua;
    string wakil;
    paslon* next;
    paslon* previous;
};


paslon* readKandidatPaslon()
{
    ifstream file("./kandidat.csv");
    
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
                dataKandidat->no_urut = stoi(cell);
            }
            else if (cellNumber == 1)
            {
                dataKandidat->ketua = cell;
            }
            else if (cellNumber == 2)
            {
                dataKandidat->wakil = cell;   
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
        dataKandidat->previous = prevKandidat;
        prevKandidat = dataKandidat;
    }

    return headKandidat;
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

void verifikasiKandidat()
{
    cout << "\n ======= Verifikasi Kandidat Paslon =======\n\n";

    paslon* headKandidatConfirmed = NULL;
    paslon* currentKandidatConfirmed = NULL;

    paslon* headKandidat = readKandidatPaslon();
    paslon* currentKandidat = headKandidat;
    while (currentKandidat != NULL)
    {
        cout << "Kandidat No. Urut: " << currentKandidat->no_urut << "\n";
        cout << "Ketua: " << currentKandidat->ketua << "\n";
        cout << "Wakil: " << currentKandidat->wakil << "\n";

        while (true)
        {
            cout << "Apakah diterima? (Ya/Tidak) ";
            string konfirmasi = "";
            cin >> konfirmasi;
            if (konfirmasi == "Ya")
            {
                cout << "Kandidat diterima!\n\n";

                paslon* kandidatConfirmed = new paslon {
                    .no_urut = currentKandidat->no_urut,
                    .ketua = currentKandidat->ketua,
                    .wakil = currentKandidat->wakil,
                };

                if (headKandidatConfirmed == NULL)
                {
                    headKandidatConfirmed = kandidatConfirmed;
                }
                kandidatConfirmed->previous = currentKandidatConfirmed;
                
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
    }
}