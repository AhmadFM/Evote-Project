#include <iostream>
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
    8. 
*/

// Surat Suara
void suratSuara(){
    // isi
}

// Voting
void voting(){
    int pilihan;

    do {
        cout << "Selamat Memilih\n";
        suratSuara();
        cout << "Pilih nomor urut kandidat pilihan Anda: "; 
        cin >> pilihan;
    } while(pilihan != 0);
}

// Lihat Jumlah Suara
void lihatJumlahSuara(){
    // prosedur
}

// Lapor Kecurangan
void laporKecurangan (){
    // proc
}

int main(){
    do {
        voting();
        laporKecurangan();
        return 0;
    } while (true);
}