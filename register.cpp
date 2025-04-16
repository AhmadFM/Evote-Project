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

    cout << "================== Register ==================\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Pilih peran (Panitia/Timses): "; 
    cin >> role;
    cout << "Masukkan Password: ";
    cin >> password;
        verificated = verifRegister(username, password, role);
    }

    


// int main() {
//     registerUser();
// }