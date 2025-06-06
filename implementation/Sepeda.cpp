#include "../model/Sepeda.h"
#include <iostream>
using namespace std;

Sepeda::Sepeda(string m, string k, int h) : merk(m), kondisi(k), harga(h) {}

void Sepeda::tampilkan() const {
    cout << "Merk: " << merk << ", Kondisi: " << kondisi << ", Harga: " << harga << endl;
}

string Sepeda::getMerk() const { return merk; }
string Sepeda::getKondisi() const { return kondisi; }
int Sepeda::getHarga() const { return harga; }

void Sepeda::setMerk(const string& m) { merk = m; }
void Sepeda::setKondisi(const string& k) { kondisi = k; }
void Sepeda::setHarga(int h) { harga = h; }
