#ifndef TIMSES_HPP
#define TIMSES_HPP

#include <string>
using namespace std;

// Struct kandidat
struct Kandidat {
    string namaKetua;
    string namaWakilKetua;
};

// Deklarasi fungsi
void tampilkanMenu();
void simpanKeCSV(const string &namaTim, const Kandidat &kandidat, const string &visi, const string &misi);
void daftarkanKandidat(Kandidat &kandidat);
void buatVisiMisi(const string &namaTim, const Kandidat &kandidat);
void editInformasiKandidat(const string &namaTim, Kandidat &kandidat);
void perbaruiCSV(const string &namaTim, const Kandidat &kandidat);
void tampilkanDataKandidat();

#endif
