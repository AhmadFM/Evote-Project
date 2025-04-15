#include <iostream>
#include <string>
using namespace std;

// struct user
struct user
{
    string username;
    string password;
    string role;
    user* next;
};

// head pointer linked list
user* head = NULL;

// Function untuk register user baru
void registerUser()
{
    user* newUser = new user;
    cout << "==== Register ====\n";
    cout << "Masukkan Username: ";
    cin >> newUser->username;
    cout << "Pilih Peran (Panitia/Tim Sukses/Pemilih): ";
    cin >> newUser->role;


    bool validPassword = false;
    do 
    {
        cout << "Masukkan Password: ";
        cin >> newUser -> password;

        int passLength = newUser -> password.length();

        if (newUser -> role == "Pemilih")
        {
            if (passLength == 16)
            {
                validPassword = true;
            }
            else
            {
                cout << "Password untuk pemilih harus 16 karakter!\n";
            }
        }
        else if (newUser -> role == "Panitia" )
        {
            if (passLength == 12 )
            {
                validPassword = true;
            }
            else
            {
                cout << "Password untuk panitia harus 12 karakter!\n";
            }
        }
        else if (newUser -> role == "Tim Sukses")
        {
            if (passLength == 12)
            {
                validPassword = true;
            }
            else
            {
                cout << "Password untuk tim sukses harus 12 karakter!\n";
            }
        }
        else
        {
            cout << "Role tidak valid. Silahkan masukkan role yang benar";
            return;
        }
    } while (!validPassword);

    newUser -> next = NULL;

    if (head == NULL)
    {
        head = newUser;
    }
    else
    {
        user* temp = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newUser;
    }
    cout << "Register berhasil.\n";
}