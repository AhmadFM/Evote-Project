#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int jenisAdmin(string username, string password) {
    string name, accPassword, accType, line;
    ifstream file("akunAdmin.csv");

    while(getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, name, ',')) {
            if (username == name) {
                getline(ss, accPassword, ',');
                if (accPassword != password) {
                    return 1;
                }
                getline(ss, accType, ',');
                return accType;
            } else {
                break;
            }
        }
    }
    return 0;
}

int verifLogin(string accountName, string accountPassword) {
    string allowedChar = "1234567890";
    bool isPemilih = true;

    for (int i = 0; i < accountPassword.length(); i++) {
        size_t x = allowedChar.find(accountPassword[i]);
        if (x == string::npos) {
            isPemilih = false;
            break;
        }
    }

    string typeOfAcc = jenisAdmin(accountName, accountPassword);

    cout << "typeOfAcc->" << typeOfAcc << " || ";

    if (typeOfAcc == "timses"){
        cout << "Tim Sukses";
    } else if (typeOfAcc == "panitia") {
        cout << "Panitia";
    } else if (typeOfAcc == 1) {
        cout << "Password yang anda masukan salah";
    } else if (typeOfAcc == 0) {
        cout << "Akun tidak ditemukan";
    } else {
        cout << "Pemilih";
    }
    return 0;
}

void verifPaslon() {
    // timses menyalonkan kandidat
    // cek timsesnya apakah sama atau tidak -> sama = gagal
    // apakah data paslon sesuai dengan ketentuan yang ada pada panitia
}

int main() {
    string name, password;

    cout << "Acount name: ";
    cin >> name;

    cout << "Password: ";
    cin >> password;

    cout << "Jenis akunmu: " << verifLogin(name, password) << endl;

    return 0;
}