#ifndef PEMILIH_HPP
#define PEMILIH_HPP

void insertCalon(int no, std::string Ketua, std::string Wakil);
bool confirm();
void suratSuara();
bool waktuVoting(time_t waktuMulai, time_t waktuAkhir, time_t sekarang);
bool waktuHasil(time_t waktuAkhir, time_t sekarang);
void voting(time_t start, time_t end, time_t now);
void cetakHasilHitungSuara();
void hitungSuara();
void lihatJumlahSuara(time_t end);
void laporKecurangan ();

#endif