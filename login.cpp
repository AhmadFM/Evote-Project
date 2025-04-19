#include <iostream>
#include <string>
#include "authentication.hpp"
#include "menuUtama.hpp"
#include "login.hpp"


using namespace std;
void login()
{
    string username, password;

    cout << "======= Login =======\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    password = inputPassword(); 


   string check = verifLogin(username, password);


    if (check == "panitia")
    {
        menuPanitia();
    }
    else if (check == "timses")
    {
        menuTimSukses();
    }
    else if (check == "pemilih")
    {
        menuPemilih(username);
    }
    else
    {
        return ;
    }
}


