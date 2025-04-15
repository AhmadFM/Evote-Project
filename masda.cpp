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

//function untuk login user
user* loginUser()
{
    string username, password;
    cout << "======= Login =======\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    user* temp  = head;
    while (temp != NULL)
    {
        if (temp -> username == username && temp -> password == password)
        {
            cout << "Login berhasil\n";
            return temp;
        }
        temp = temp-> next;
    }

    cout << "Login gagal. Silahkan coba kembali. \n";
    return NULL;
}

void menuPanitia()
{
    int pilihan ;
    do
    {
        cout << "\n ======= Menu Panitia =======\n";
        cout << "1. Atur ketentuan pemilu\n";
        cout << "2. Verifikasi pasangan calon\n";
        cout << "3. Edit data pemilih\n";
        cout << "4. Verifikasi gugatan/laporan\n";
        cout << "0. Kembali\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Atur ketentuan pemilu\n";
                break;
            case 2:
                cout << "Verifikasi pasangan calon\n";
                break;
            case 3: 
                cout << "Edit data pemilih\n";
                break;
            case 4:
                cout << "Verifikasi gugatan/laporan";
                break;
            case 0:
                cout << "Kembali ke menu utama\n";
            
        }
    } while (pilihan != 0);
    
}

void menuTimSukses()
{
    int pilihan;

    do
    {
        cout << "\n ====== Menu Tim Sukses ======\n";
        cout << "1. Form pengajuan pasangan calon\n";
        cout << "2. Edit Informasi pasangan calon\n";
        cout << "3. Form gugatan\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1: 
                cout << "Form pengajuan pasangan calon\n";
                break;
            case 2:
                cout << "Edit informasi pasangan calon\n";
                break;
            case 3:
                cout << "Form gugatan\n";
                break;
            case 0:
                cout << "Kembali ke menu utama\n";

        }
    } while (pilihan != 0);
    
}

void menuPemilih()
{
    int pilihan;

    do
    {
        cout << "\n ======= Menu Pemilih =======\n";
        cout << "1. Voting\n";
        cout << "2. Cek hasil pemilu\n";
        cout << "3. Lapor kecurangan\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Voting\n";
                break;
            case 2:
                cout << "Cek hasil pemilu\n";
                break;
            case 3:
                cout << "Lapor kecurangan\n";
                break;
            case 0:
                cout << "Terima kasih.\n";

        }

    } while (pilihan != 0);
    
}

void menuUtama(user* user)
{
    cout << "\n ======= Menu Utama =======\n";
    cout << "Selamat datang, " << user -> username  << " (" << user -> role << ")" << endl;
    
    if (user -> role == "Tim Sukses")
    {
        menuTimSukses();
    }
    else if (user -> role == "Pemilih")
    {
        menuPemilih();
    }
    else if (user -> role == "Panitia")
    {
        menuPanitia();
    }
    else 
    {
        cout << "role tidak ditemukan.";
    };
}


int main()
{
    int pilihan;
    user* loggedInUser = NULL;

    do
    {
        cout << "\n======= Sistem Pemilihan Umum E-Vote =======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "0. Keluar\n";
        cout << "Pilih Opsi: \n";      
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                registerUser();
                break;
            case 2:
                loggedInUser = loginUser();
                if (loggedInUser != NULL)
                {
                    menuUtama(loggedInUser);
                }
                break;
            case 0:
                cout << "Terima kasih telah meluangkan waktu Anda\n";
                return 0;
            default:
                cout << "Pilihan tidak valid\n";
        }
        } while (pilihan !=3);
        return 0;

    }