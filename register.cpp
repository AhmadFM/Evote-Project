#include <iostream>
#include <string>
#include <fstream>
#include "register.hpp"
#include "authentication.hpp"

using namespace std;

void registerUser ()
{
    string username, password, role;

    cout << "================== Register ==================\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Pilih peran (panitia/timses/pemilih): "; 
    cin >> role;
    cout << "Masukkan Password: ";
    cin >> password;

    verifRegister(username, password, role);
}
