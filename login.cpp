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
    cin >> password;

   string check = verifLogin(username, password);


    if (check == "Panitia")
    {
        menuPanitia();
    }
    else if (check == "Tim Sukses")
    {
        menuTimSukses();
    }
    else if (check == "Pemilih")
    {
        menuPemilih();
    }
    else
    {
        return ;
    }
}


