#include <iostream>
#include <string>
#include "authentication.cpp"



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
        return "Pengguna diarahkan ke menu panitia.\n";
    }
    else if (check == "tim sukses")
    {
        return "Pengguna diarahkan ke menu tim sukses.\n";
    }
    else if (check == "pemilih")
    {
        return "Pengguna diarahkan ke menu pemilih.\n";
    }
    else
    {
        return "Login gagal. Silahkan coba kembali.\n";
    }
}
