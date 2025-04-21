#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>

#include "timses.hpp"

using namespace std;

// Menu Timses
void tampilkanMenu() {
    system("cls");
    cout << "\n+---------------------------------------+" << endl;
    cout << "|            Menu Tim Sukses            |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| 1. Daftarkan Ketua dan Wakil Ketua    |" << endl;
    cout << "| 2. Buat Visi dan Misi                 |" << endl;
    cout << "| 3. Edit Informasi Kandidat            |" << endl;
    cout << "| 4. Lapor Gugatan Paslon               |" << endl;
    cout << "|                                       |" << endl;
    cout << "| 5. Keluar                             |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "Pilih opsi >>> ";
}

// simpan data kandidat kedalam file kandidat.csv
void simpanKeCSV(const string &namaTim, const Kandidat &kandidat, const string &visi, const string &misi) {
    ofstream file("calon_kandidat.csv", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << namaTim << "," << kandidat.namaKetua << "," << kandidat.namaWakilKetua << "," << visi << "," << misi << endl;
        file.close();
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|        Data berhasil disimpan!        |" << endl;
        cout << "+---------------------------------------+" << endl;
    } else {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|    Gagal membuka file kandidat.csv!   |" << endl;
        cout << "+---------------------------------------+" << endl;
    }
}

// 1. daftarkan ketua dan wakil
void daftarkanKandidat(Kandidat &kandidat) {
    cout << "| Masukkan nama Ketua: ";
    getline(cin, kandidat.namaKetua);
    cout << "| Masukkan nama Wakil Ketua: ";
    getline(cin, kandidat.namaWakilKetua);
    system("cls");
    cout << "\n+---------------------------------------+" << endl;
    cout << "|     Kandidat berhasil didaftarkan     |" << endl;
    cout << "+---------------------------------------+" << endl;
}

// 2. membuat visi dan misi
void buatVisiMisi(const string &namaTim, const Kandidat &kandidat) {
    if (kandidat.namaKetua.empty() || kandidat.namaWakilKetua.empty()) {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|   Anda belum mendaftarkan kandidat!   |" << endl;
        cout << "+---------------------------------------+" << endl;
    } else {
        string visi, misi;
        cout << "| Masukkan Visi: ";
        getline(cin, visi);
        cout << "| Masukkan Misi: ";
        getline(cin, misi);

        // Simpan nama tim, ketua, wakil, visi, dan misi ke file kandidat.csv
        simpanKeCSV(namaTim, kandidat, visi, misi);
    }
}

// update csv (rewrite)
void perbaruiCSV(const string &namaTim, const Kandidat &kandidat) {
    ifstream fileInput("calon_kandidat.csv");
    ofstream fileOutput("calon_kandidat_temp.csv");
    bool ditemukan = false;

    if (fileInput.is_open() && fileOutput.is_open()) {
        string line;
        while (getline(fileInput, line)) {
            stringstream ss(line);
            string namaTimCSV, namaKetuaCSV, namaWakilCSV, visiCSV, misiCSV;

            // Membaca data dari baris CSV
            getline(ss, namaTimCSV, ',');
            getline(ss, namaKetuaCSV, ',');
            getline(ss, namaWakilCSV, ',');
            getline(ss, visiCSV, ',');
            getline(ss, misiCSV, ',');

            if (namaTimCSV == namaTim) {
                // Jika nama tim cocok, perbarui data kandidat
                fileOutput << namaTim << "," << kandidat.namaKetua << "," << kandidat.namaWakilKetua << "," << visiCSV << "," << misiCSV << endl;
                ditemukan = true;
            } else {
                // Jika tidak cocok, tulis ulang data lama
                fileOutput << line << endl;
            }
        }

        fileInput.close();
        fileOutput.close();

        // Ganti file lama dengan file baru
        remove("calon_kandidat.csv");
        rename("calon_kandidat_temp.csv", "calon_kandidat.csv");

        if (ditemukan) {
            system("cls");
            cout << "\n+---------------------------------------+" << endl;
            cout << "|   Data kandidat berhasil diperbarui   |" << endl;
            cout << "+---------------------------------------+" << endl;
        } else {
            system("cls");
            cout << "\n+---------------------------------------+" << endl;
            cout << "|       Nama tim tidak ditemukan,       |" << endl;
            cout << "|       tidak ada perubahan.            |" << endl;
            cout << "+---------------------------------------+" << endl;
        }
    } else {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|          Gagal membuka file!          |" << endl;
        cout << "+---------------------------------------+" << endl;
    }
}

// Fungsi untuk mengedit informasi Ketua dan Wakil Ketua
void editInformasiKandidat(const string &namaTim, Kandidat &kandidat) {
    if (kandidat.namaKetua.empty() || kandidat.namaWakilKetua.empty()) {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|  Belum ada kandidat yang terdaftar,   |" << endl;
        cout << "|  Silahkan daftarkan kandidat anda.    |" << endl;
        cout << "+---------------------------------------+" << endl;
    } else {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|      Informasi kandidat saat ini      |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "| Nama Ketua: " << kandidat.namaKetua << endl;
        cout << "| Nama Wakil Ketua: " << kandidat.namaWakilKetua << endl;
        cout << "+---------------------------------------+" << endl;

        cout << "Masukkan nama Ketua baru (kosongkan jika tidak ingin mengubah): ";
        string namaKetuaBaru;
        getline(cin, namaKetuaBaru);
        if (!namaKetuaBaru.empty()) {
            kandidat.namaKetua = namaKetuaBaru;
        }

        cout << "Masukkan nama Wakil Ketua baru (kosongkan jika tidak ingin mengubah): ";
        string namaWakilBaru;
        getline(cin, namaWakilBaru);
        if (!namaWakilBaru.empty()) {
            kandidat.namaWakilKetua = namaWakilBaru;
        }

        // Perbarui data di file .csv
        perbaruiCSV(namaTim, kandidat);
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|Informasi kandidat berhasil diperbarui!|" << endl;
        cout << "+---------------------------------------+" << endl;
    }
}


// Fungsi untuk melaporkan gugatan paslon
void laporGugatanPaslon(const string &namaTim) {
    if (namaTim.empty()) {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "| Kamu belum menambahkan Nama timsukses |" << endl;
        cout << "+---------------------------------------+" << endl;
        return; // Keluar dari fungsi jika nama tim kosong
    }

    string pasanganNomor, isiGugatan;
    cout << "\n+---------------------------------------+" << endl;
    cout << "|       Form Lapor Gugatan Paslon       |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| Lapor gugatan untuk pasangan nomor: ";
    getline(cin, pasanganNomor);
    cout << "| Isi Gugatan: ";
    getline(cin, isiGugatan);

    // Format nama tim sukses penggugat
    string timPenggugat = namaTim + "_penggugat";
    string timTergugat = pasanganNomor + "_tergugat";
    // Simpan laporan ke file laporan_gugatan.csv
    ofstream file("laporan_gugatan.csv", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << timPenggugat << "," << timTergugat << "," << isiGugatan << endl;
        file.close();
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|   Laporan gugatan berhasil disimpan   |" << endl;
        cout << "+---------------------------------------+" << endl;
    } else {
        system("cls");
        cout << "\n+---------------------------------------+" << endl;
        cout << "|          Gagal membuka file!          |" << endl;
        cout << "+---------------------------------------+" << endl;
    }
}



void main_timses() {
    Kandidat kandidat;
    bool sudahTerdaftar = false;
    string namaTim;
    
    while (true) {
        cout << "+---------------------------------------+" << endl;
        cout << " Masukkan nama Tim Sukses: ";
        cin.ignore(); // Membersihkan buffer input
        getline(cin, namaTim);

        if (namaTim.empty()) {
            cout << "+---------------------------------------+" << endl;
            cout << "| Nama Tim Sukses tidak boleh kosong    |" << endl;
            cout << "+---------------------------------------+" << endl;
        } else {
            break;
        }
    }
    
    while (true) {
        tampilkanMenu();
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input
        system("cls");

        if (pilihan == 1) {
            if (sudahTerdaftar) {
                system("cls");
                cout << "+------------------------------------------------+" << endl;
                cout << "| Ups, Anda telah mendaftarkan pasangan kandidat |" << endl;
                cout << "+------------------------------------------------+" << endl;
            } else {
                daftarkanKandidat(kandidat);
                sudahTerdaftar = true;
            }
        } else if (pilihan == 2) {
            buatVisiMisi(namaTim, kandidat);
        } else if (pilihan == 3) {
            editInformasiKandidat(namaTim, kandidat);
        } else if (pilihan == 4) {
            laporGugatanPaslon(namaTim);
        } else if (pilihan == 5) {
            system("cls");
            break;
        } else {
            system("cls");
            cout << "+---------------------------------------+" << endl;
            cout << "|      Masukan pilihan yang sesuai      |" << endl;
            cout << "+---------------------------------------+" << endl;
        }

        cout << endl;
    }

}