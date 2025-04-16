#ifndef PEMILIH_HPP
#define PEMILIH_HPP

#include <iostream>
#include <ctime>
#include <string>

void insertCalon(int no, std::string Ketua, std::string Wakil);
bool confirm();
int suratSuara();
bool waktuVoting(time_t waktuMulai, time_t waktuAkhir, time_t sekarang);
bool waktuHasil(time_t waktuAkhir, time_t sekarang);
void kirimSuara(int no_urut, std::string username, time_t date);
void voting(time_t start, time_t end, time_t now, std::string username);
void cetakHasilHitungSuara();
void hitungSuara();
void lihatJumlahSuara(time_t end);
void laporKecurangan ();

#endif