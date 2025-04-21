#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <conio.h> // password asterisk
#include "authentication.hpp"
using namespace std;

struct node {
    string name;
    string password;
    string type;
    node *next;
};

void addUser(string newName, string newPass, string newType) {
    node *head = NULL;
    node *newUser = new node();
    if (!head) {
        head = newUser;
    } else {
        node *temp = head;
        while (temp->next) {
            temp = temp->next;
            temp->next = newUser;
        }
    }
}

void getAccData(string fileName) {
    ifstream file(fileName);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, password, type;

        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, type, ',');
        
        addUser(name, password, type);
    }
}

void saveNewAcc(string filename, string nama, string pass, string jenis) {
    string lastLine;
    ifstream checkFile(filename);
    if (checkFile.is_open()) {
        string line;
        while (getline(checkFile, line)) {
            lastLine = line;
        }
        checkFile.close();
    }
    
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        if (!lastLine.empty() && lastLine.back() != '\n') {
            file << "\n";
        }
        file << nama << "," << pass << "," << jenis;

        file.close();
    } else {
        cout << "+---------------------+" << endl;
        cout << "| Gagal membuka file! |" << endl;
        cout << "+---------------------+" << endl;
    }
}

bool nameInData(string Name) {
    node *head = NULL;
    node *temp = head;
    while (temp) {
        if (temp->name == Name) {
            return true;
            temp = temp->next;
        }
    }
    return false;
}

bool isInType(string type) {
    return type == "panitia" || type == "timses" || type == "pemilih";
}

bool validPassword(string type, string password) {
    if (type == "panitia" || type == "timses") {
        if (password.length() < 8 || password.length() > 12) {
            return false;
        }

        bool hurufIn = false, angkaIn = false, simbolIn = false;

        for (int i = 0; i < password.length(); i++) {
            char check = password[i];
            if (isalpha(check)) {
                hurufIn = true;
            } else if (isdigit(check)) {
                angkaIn = true;
            } else {
                simbolIn =  true;
            }
        }
        return hurufIn && angkaIn && simbolIn;

    } else if (type == "pemilih") {
        if (password.length() != 16) {
            return false;
        }

        for (int i = 0; i < password.length(); i++) {
            char check = password[i];
            
            if (!isdigit(check)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool verifRegister(string nama, string password, string jenis) {
    // mengecek apakah username sudah digunakan di akun lain
    // mengecek apakah pilihan user sesuai dengan kriteria aun yang ada
    // mengecek apakah password valid sesuai jenis akun yang dipilih sebelumnya
    if (nameInData(nama)) {
        cout << "\n+--------------------------------------+" << endl;
        cout << "| Nama sudah digunakan, coba nama lain |" << endl;
        cout << "+--------------------------------------+" << endl;
        return false;
    }

    if (!isInType(jenis)) {
        cout << "\n+------------------------------+" << endl;
        cout << "| Pilih jenis akun yang sesuai |" << endl;
        cout << "+------------------------------+" << endl;
        return false;
    }

    if (!validPassword(jenis, password)) {
        cout << "\n+-----------------------------------------------------+" << endl;
        cout << "| Maaf, assword harus lebih dari 8 dan kurang dari 12 |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        return false;
    }

    addUser(nama, password, jenis);
    saveNewAcc("akun.csv", nama, password, jenis);
    cout << "\n+-----------------------+" << endl;
    cout << "|  Registrasi berhasil  |" << endl;
    cout << "+-----------------------+" << endl << endl;
    return true;
}



string jenisAdmin(string username, string password) {
    string name, accPassword, accType, line;
    ifstream file("akun.csv");

    while(getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, name, ',')) {
            if (username == name) {
                getline(ss, accPassword, ',');
                if (accPassword != password) {
                    return "unmatched";
                }
                getline(ss, accType, ',');
                return accType;
            } else {
                break;
            }
        }
    }
    return "notfound";
}

string verifLogin(string accountName, string password) {
    string typeOfAcc = jenisAdmin(accountName, password);

    if (typeOfAcc == "Timses"){
        cout << "\n+------------------+" << endl;
        cout << "|  Login berhasil  |" << endl;
        cout << "+------------------+" << endl;
    } else if (typeOfAcc == "Panitia") {
        cout << "\n+------------------+" << endl;
        cout << "|  Login berhasil  |" << endl;
        cout << "+------------------+" << endl;
    } else if (typeOfAcc == "unmatched") {
        cout << "\n+----------------------------------+" << endl;
        cout << "| Password yang anda masukan salah |" << endl;
        cout << "+----------------------------------+" << endl;
    } else if (typeOfAcc == "notfound") {
        cout << "\n+----------------------+" << endl;
        cout << "| Akun tidak ditemukan |" << endl;
        cout << "+----------------------+" << endl;
    } else {
        cout << "\n+------------------+" << endl;
        cout << "|  Login berhasil  |" << endl;
        cout << "+------------------+" << endl;
    }   
    return typeOfAcc;
}

void verifPaslon() {
    // timses menyalonkan kandidat
    // cek timsesnya apakah sama atau tidak -> sama = gagal
    // apakah data paslon sesuai dengan ketentuan yang ada pada panitia
}

std::string inputPassword() {
    std::string password;
    char ch;

    while ((ch = _getch()) != 13) { // 13 = Enter
        if (ch == 8) { // Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return password;
}


// int main() {
//     string name, password;

//     cout << "Acount name: ";
//     cin >> name;

//     cout << "Password: ";
//     cin >> password;

//     cout << "Jenis akunmu: " << verifLogin(name, password) << endl;

//     return 0;
// }

// int main() {
//     cout << validPassword("pemilih", "1263284384697732");
// }