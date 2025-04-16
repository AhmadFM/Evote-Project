#include <iostream>
#include <string>
#include <fstream>
#include "register.hpp"
#include "authentication.hpp"

using namespace std;

void registerUser ()
{
    string username, password, role;
    bool verificated = false;

<<<<<<< HEAD
    cout << "================== Register ==================\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Pilih peran (Panitia/Timses): "; 
    cin >> role;
    cout << "Masukkan Password: ";
    cin >> password;
=======
    while (!verificated) {
        cout << "================== Register ==================\n";
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Pilih peran (panitia/timses/pemilih): "; 
        cin >> role;
        cout << "Masukkan Password: ";
        cin >> password;
>>>>>>> 7da67d8bf9ac3aac408b9ec9e059fccb7ee025d0

        verificated = verifRegister(username, password, role);
    }

    
}

// int main() {
//     registerUser();
// }