#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "pemilih.hpp"
using namespace std;

struct calon{
    int noUrut;
    string ketua;
    string wakil;
    int count;
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
void insertCalon(int no, string Ketua, string Wakil){
    calon *new_calon;
    new_calon = new calon;
    new_calon -> noUrut = no;
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

void suratSuara(){
    ifstream file("kandidat.csv");
    string line, ketua, wakil, visi, misi, noUrut;
    
    cout << "===== Surat Suara =====\n";
    while(getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, noUrut, ',')) {
            getline(ss, ketua, ',');
            getline(ss, wakil, ',');
            getline(ss, visi, ',');
            getline(ss, misi, ',');
            cout << noUrut << endl;
            cout << ketua << " & " << wakil << endl;
            cout << "visi : " << visi << endl; 
            cout << "misi : " << misi << endl;
            cout << "-----------------------\n";
        }
    }
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
        current = head;
        while (current!=NULL)
        {
            cout << current->noUrut << ".|";
            cout << current->ketua << "\t&\t";
            cout << current->wakil << "\t| ";
            cout << current->count << " Suara" << endl;
            current = current -> next;
        }
    }
}

// Voting
void voting(time_t start = time(0), time_t end = time(0), time_t now = time(0)){
    if (waktuVoting(start, end, now)){
        bool cek = false;
        do {
            cout << "\n===== Selamat Memilih =====\n";
            suratSuara();
            string pilih; 
            while (true){
                cout << "Pilih nomor urut kandidat pilihan Anda: "; 
                cin >> pilih;
                if (pilih == "1" or pilih == "2" or pilih == "3"){
                    break;
                } else{
                    cout << "Maaf, input tidak sesuai" << endl;
                }
                
            }
            
            if(confirm()){
                cek = true;
                //Kirim hasil voting
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
    ifstream file("suara.csv");
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string no;
        getline(ss, no, ',');
        
        int urut = stoi(no);
        current = head;
        while (current != NULL){
            if (current-> noUrut != urut){
                current = current -> next;
            } else{
                current -> count = current -> count + 1;
                break;
            }
        }
    }
} 

// Lihat Jumlah Suara
void lihatJumlahSuara(time_t end = time(0)){
    if (waktuHasil(end)){
        ifstream file("kandidat.csv");
        string line, no, Ketua, Wakil;
        while(getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, no, ',')){
                getline(ss, Ketua, ',');
                getline(ss, Wakil, ',');

                int urut = stoi(no);
                cout << urut << " " << Ketua << " " << Wakil << endl;
                insertCalon(urut, Ketua, Wakil);
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

// MAIN Lapor Kecurangan
void laporKecurangan (){
    string judul, referensi, deskripsi;
    cout << "==== Formulir Laporan Kecurangan ====" << endl;
    cout << "Judul: "; getline(cin, judul);
    cout << "Link bukti: "; getline(cin, referensi);
    cout << "Deskripsi: "; getline(cin, deskripsi);
}

// int main(){
//     do {
//         voting();
//         laporKecurangan();
//         return 0;
//     } while (true);
// }