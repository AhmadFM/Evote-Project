#include <iostream>
#include <string>
#include "authentication.cpp"
#include "menuUtama.cpp"



using namespace std;

string login ()
{
    string username, password;

    cout << "======= Login =======\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

   string check = verifLogin(username, password);


    if (check == "panitia")
    {
        menuPanitia();
    }
    else if (check == "tim sukses")
    {
        menuTimSukses();
    }
    else if (check == "pemilih")
    {
        menuPemilih();
    }
    else
    {
        return "Login gagal. Silahkan coba kembali.\n";
    }
}

