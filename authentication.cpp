#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string jenisAdmin(string username, string password) {
    string name, accPassword, accType, line;
    ifstream file("akunAdmin.csv");

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
    string allowedChar = "1234567890";
    bool isPemilih = true;

    for (int i = 0; i < password.length(); i++) {
        size_t x = allowedChar.find(password[i]);
        if (x == string::npos) {
            isPemilih = false;
            break;
        }       
    }

    string typeOfAcc = jenisAdmin(accountName, password);

    if (typeOfAcc == "Timses"){
        return "Tim Sukses";
    } else if (typeOfAcc == "Panitia") {
        return "Panitia";
    } else if (typeOfAcc == "unmatched") {
        return "Password yang anda masukan salah";
    } else if (typeOfAcc == "notfound") {
        return "Akun tidak ditemukan";
    } else {
        return "Pemilih";
    }   
    return "";
}

void verifPaslon() {
    // timses menyalonkan kandidat
    // cek timsesnya apakah sama atau tidak -> sama = gagal
    // apakah data paslon sesuai dengan ketentuan yang ada pada panitia
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