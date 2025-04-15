#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// step ketika memilih
/*
    1. Pendataan oleh panitia pemilu
    2. Mendapatkan alat untuk memilih (Nama NIK)
    3. datang ke tps
    4. validasi identitas
    5. masuk ke bilik suara
    6. coblos
    7. masukan hasil ke kotak suara
*/

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

// Voting
void voting(time_t start = time(0), time_t end = time(0), time_t now = time(0)){
    cout << start << endl << end << endl << now << endl;
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

// Lihat Jumlah Suara
void lihatJumlahSuara(){
    
}

// Lapor Kecurangan
void laporKecurangan (){
    // proc
}

int main(){
    do {
        voting();
        lihatJumlahSuara();
        laporKecurangan();
        return 0;
    } while (true);
}