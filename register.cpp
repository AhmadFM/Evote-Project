#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "register.hpp"
#include "authentication.hpp"

using namespace std;

void registerUser ()
{
    string username, password, role;
    bool verificated = false;

    cout << "+---------------------------------------+" << endl;
    cout << "|                REGISTER               |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| Username: ";
    cin >> username;
    cout << "| Tipe Akun (panitia/timses): "; 
    cin >> role;
    cout << "| Password: ";
    password = inputPassword(); //
    verificated = verifRegister(username, password, role);
}

    


// int main() {
//     registerUser();
// }