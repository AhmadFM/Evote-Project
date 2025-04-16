#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "timses.hpp"

using namespace std;

// Menu Timses
void tampilkanMenu() {
    cout << "=== Menu Tim Sukses ===" << endl;
    cout << "1. Daftarkan Ketua dan Wakil Ketua" << endl;
    cout << "2. Buat Visi dan Misi" << endl;
    cout << "3. Edit Informasi Kandidat" << endl;
    cout << "4. Lapor Gugatan Paslon" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih opsi: ";
}

// simpan data kandidat kedalam file kandidat.csv
void simpanKeCSV(const string &namaTim, const Kandidat &kandidat, const string &visi, const string &misi) {
    ofstream file("kandidat.csv", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << namaTim << "," << kandidat.namaKetua << "," << kandidat.namaWakilKetua << "," << visi << "," << misi << endl;
        file.close();
        cout << "Data tim sukses, kandidat, visi, dan misi berhasil disimpan ke kandidat.csv!" << endl;
    } else {
        cout << "Gagal membuka file kandidat.csv!" << endl;
    }
}

// 1. daftarkan ketua dan wakil
void daftarkanKandidat(Kandidat &kandidat) {
    cout << "Masukkan nama Ketua: ";
    getline(cin, kandidat.namaKetua);
    cout << "Masukkan nama Wakil Ketua: ";
    getline(cin, kandidat.namaWakilKetua);
    cout << "Kandidat berhasil didaftarkan!" << endl;
}

// 2. membuat visi dan misi
void buatVisiMisi(const string &namaTim, const Kandidat &kandidat) {
    if (kandidat.namaKetua.empty() || kandidat.namaWakilKetua.empty()) {
        cout << "Anda belum mendaftarkan siapapun untuk menjadi Kandidat dalam Tim Sukses anda!" << endl;
    } else {
        string visi, misi;
        cout << "Masukkan Visi: ";
        getline(cin, visi);
        cout << "Masukkan Misi: ";
        getline(cin, misi);

        // Simpan nama tim, ketua, wakil, visi, dan misi ke file kandidat.csv
        simpanKeCSV(namaTim, kandidat, visi, misi);
    }
}

// update csv (rewrite)
void perbaruiCSV(const string &namaTim, const Kandidat &kandidat) {
    ifstream fileInput("kandidat.csv");
    ofstream fileOutput("kandidat_temp.csv");
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
        remove("kandidat.csv");
        rename("kandidat_temp.csv", "kandidat.csv");

        if (ditemukan) {
            cout << "Data kandidat berhasil diperbarui di file kandidat.csv!" << endl;
        } else {
            cout << "Nama tim tidak ditemukan di file kandidat.csv. Tidak ada perubahan yang dilakukan." << endl;
        }
    } else {
        cout << "Gagal membuka file kandidat.csv!" << endl;
    }
}

// Fungsi untuk mengedit informasi Ketua dan Wakil Ketua
void editInformasiKandidat(const string &namaTim, Kandidat &kandidat) {
    if (kandidat.namaKetua.empty() || kandidat.namaWakilKetua.empty()) {
        cout << "Belum ada kandidat yang terdaftar. Silakan daftarkan kandidat terlebih dahulu." << endl;
    } else {
        cout << "Informasi kandidat saat ini:" << endl;
        cout << "Nama Ketua: " << kandidat.namaKetua << endl;
        cout << "Nama Wakil Ketua: " << kandidat.namaWakilKetua << endl;

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

        cout << "Informasi kandidat berhasil diperbarui!" << endl;
    }
}


// Fungsi untuk melaporkan gugatan paslon
void laporGugatanPaslon(const string &namaTim) {
    if (namaTim.empty()) {
        cout << "Kamu belum menambahkan Nama timsukses" << endl;
        return; // Keluar dari fungsi jika nama tim kosong
    }

    string pasanganNomor, isiGugatan;
    cout << "=== Form Lapor Gugatan Paslon ===" << endl;
    cout << "Masukkan laporan gugatan untuk pasangan nomor: ";
    getline(cin, pasanganNomor);
    cout << "Isi Gugatan: ";
    getline(cin, isiGugatan);

    // Format nama tim sukses penggugat
    string timPenggugat = namaTim + "_penggugat";
    string timTergugat = pasanganNomor + "_tergugat";
    // Simpan laporan ke file laporan_gugatan.csv
    ofstream file("laporan_gugatan.csv", ios::app); // Membuka file dalam mode append
    if (file.is_open()) {
        file << timPenggugat << "," << timTergugat << "," << isiGugatan << endl;
        file.close();
        cout << "Laporan gugatan berhasil disimpan ke laporan_gugatan.csv!" << endl;
    } else {
        cout << "Gagal membuka file laporan_gugatan.csv!" << endl;
    }
}

void main_timses() {
    Kandidat kandidat;
    bool sudahTerdaftar = false;
    string namaTim;

    while (true) {
        cout << "Masukkan nama Tim Sukses: ";
        getline(cin, namaTim);

        if (!namaTim.empty()) {
            break;
        } else {
            cout << "Nama Tim Sukses tidak boleh kosong. Silakan coba lagi." << endl;
        }
    }

    while (true) {
        tampilkanMenu();
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        if (pilihan == 1) {
            if (sudahTerdaftar) {
                cout << "Anda sudah mendaftarkan pasangan kandidat. Tidak dapat mendaftarkan lagi." << endl;
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
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    }

}