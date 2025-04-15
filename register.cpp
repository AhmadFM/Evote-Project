#include <iostream>
#include <string>
#include <fstream>
#include "register.hpp"

using namespace std;

void registerUser ()
{
    string username, password, role;

    cout << "================== Register ==================\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Pilih peran (Panitia/Tim Sukses/Pemilih): "; 
    cin >> role;

    while (role != "Panitia" && role != "Tim Sukses" && role != "Pemilih")
    {
        cout << "Peran tidak valid. Silakan masukkan peran sesuai ketentuan yang ada.\n ";
        cin >> role;
    }
    cout << "Masukkan Password: ";
    cin >> password;

    ofstream file("akunAdmin.csv", ios::app);
    if (file.is_open())
    {
        file << username << "," << password << "," << role << "\n";
        file.close();
        cout << "Register berhasil.\n";
    }
    else
    {
        cout << "Gagal membuka file untuk menyimpan data.\n";
    }
}
