#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void registerUser ()
{
    string username, password, role;

    cout << "================== Register ==================\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Pilih peran (Panitia/Tim Sukses/Pemilih): ";
    cin >> role;
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
