#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include "pemilih.hpp"
using namespace std;

struct calon{
    string timSukses;
    string ketua;
    string wakil;
    int count = 0;
    calon *next;
};

calon *head = NULL, *current = NULL;

// cek isi list
bool isEmpty(){
    if(head == NULL){
        return 1;
    } return 0;
}

//masukan calon ke list
void insertCalon(string timSukses, string Ketua, string Wakil){
    calon *new_calon;
    new_calon = new calon;
    new_calon -> timSukses = timSukses;
    new_calon -> ketua = Ketua;
    new_calon -> wakil = Wakil;
    new_calon -> count = 0;
    new_calon -> next = NULL;
    if (isEmpty())
    {
        head = new_calon;
        head -> next = NULL;
    } else{
        current = head;
        while(current->next != NULL){
            current = current -> next;
        }
        current -> next = new_calon;
    }
}

bool confirm(){
    bool cek = false;
    while (cek != true){
        cout << "anda yakin dengan pilihan anda?(Y/n)";
        string yakin; cin >> yakin;
        if (yakin == "Y" || yakin  == "y"){
            return 1;
        }else if(yakin == "N" || yakin == "n"){
            return 0;
        }
        cout << "Maaf, input tidak sesuai" << endl;
    }
    return 0;
}

int suratSuara(){
    ifstream file("confirmedKandidat.csv");
    string line, ketua, wakil, visi, misi, timSukses;

    int noUrut = 1;
    
    cout << "===== Surat Suara =====\n";
    while(getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, timSukses, ',')) {
            getline(ss, ketua, ',');
            getline(ss, wakil, ',');
            getline(ss, visi, ',');
            getline(ss, misi, ',');
            cout << noUrut << endl;
            cout << timSukses << endl;
            cout << ketua << " & " << wakil << endl;
            cout << "visi : " << visi << endl; 
            cout << "misi : " << misi << endl;
            cout << "-----------------------\n";
        }
        noUrut++;
    }

    return noUrut;
}

bool waktuVoting(time_t waktuMulai, time_t waktuAkhir, time_t sekarang) {
    return (sekarang >= waktuMulai && sekarang <= waktuAkhir);
}

bool waktuHasil(time_t waktuAkhir, time_t sekarang = time(0)){
    return (waktuAkhir == sekarang);
}


void cetakHasilHitungSuara(){
    if (!isEmpty())
    {
        calon* cr = head;
        while (cr!=NULL)
        {
            cout << cr->timSukses << ".|";
            cout << cr->ketua << "\t&\t";
            cout << cr->wakil << "\t| ";
            cout << cr->count << " Suara" << endl;
            cr = cr -> next;
        }
    }
}

void kirimSuara(int no_urut, string username, time_t date)
{
    string lastLine;
    ifstream checkFile("./suara.csv");
    if (checkFile.is_open()) {
        string line;
        while (getline(checkFile, line)) {
            lastLine = line;
        }
        checkFile.close();
    }
    
    ofstream file("./suara.csv", ios::app);
    if (file.is_open()) {
        if (!lastLine.empty() && lastLine.back() != '\n') {
            file << "\n";
        }
        file << no_urut << "," << username << "," << date;

        file.close();
    } else {
        cout << "Gagal membuka file.\n";
    }
}

// Voting
void voting(time_t start, time_t end, time_t now, string username){
    // hanya bisa sekali voting
    ifstream checkFile("./suara.csv");
    string lastLine; 
    if (checkFile.is_open()) { 
        string line;     
        while (getline(checkFile, line)) {
            lastLine = line; 
        }
        checkFile.close();
    }
    stringstream ss(lastLine);
    string noUrut, user, date;
    getline(ss, noUrut, ',');
    getline(ss, user, ',');
    getline(ss, date, ',');
    if (user == username){
        cout << "Anda sudah melakukan voting!" << endl;
        return;
    }
        if (waktuVoting(start, end, now)){
        bool cek = false;
        do {
            cout << "\n===== Selamat Memilih =====\n";
            int jumlahPaslon = suratSuara();
            int pilih; 
            while (true){
                cout << "Pilih nomor urut kandidat pilihan Anda: "; 
                cin >> pilih;
                if (pilih > 0 && pilih < jumlahPaslon){
                    break;
                } else{
                    cout << "Maaf, input tidak sesuai" << endl;
                }
                
            }
            
            if(confirm()){
                cek = true;
                kirimSuara(pilih, username, now);
            }else {
                cek = false;
            }
        } while(cek != true);
        cout << "Terima kasih, telah menggunakan hak suara Anda!" << endl;
    } else{
        cout << "Maaf, waktu memilih tidak sesuai!\n";
        return;
    }
}
void hitungSuara(){
    calon* cr = head;
    while (cr != NULL)
    {
        cr->count = 0;
        cr = cr->next;
    }

    ifstream file("suara.csv");
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string no;
        getline(ss, no, ',');
        int noUrutPilihan = stoi(no);
        
        int noUrut = 1;
        current = head;
        while (current != NULL){
            if (noUrut != noUrutPilihan){
                current = current -> next;
            } else{
                current -> count = current -> count + 1;
                break;
            }
            noUrut++;
        }
    }
} 

// Lihat Jumlah Suara
void lihatJumlahSuara(time_t end = time(0)){
    if (waktuHasil(end)){
        head = NULL;
        
        ifstream file("confirmedKandidat.csv");
        string line, no, Ketua, Wakil;
        while(getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, no, ',')){
                getline(ss, Ketua, ',');
                getline(ss, Wakil, ',');

                string timSukses = no;
                // cout << timSukses << " " << Ketua << " " << Wakil << endl;
                insertCalon(timSukses, Ketua, Wakil);
                break;
            }
        }
        
        hitungSuara();
        cout << "==== Hasil Akumulasi Voting ====" << endl;
        cetakHasilHitungSuara();
        return;
    } else{
        cout << "Maaf, masa pemilihan masih berjalan!\n";
        return;
    }
}

// int main(){
//     do {
//         voting();
//         laporKecurangan();
//         return 0;
//     } while (true);
// }