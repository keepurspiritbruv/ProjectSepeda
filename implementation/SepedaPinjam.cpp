#include "../model/SepedaPinjam.h"
#include <iostream>
using namespace std;

SepedaPinjam::SepedaPinjam(string m, string k, int h, bool t)
    : Sepeda(m, k, h), tersedia(t) {}

bool SepedaPinjam::isTersedia() const { return tersedia; }
void SepedaPinjam::setTersedia(bool t) { tersedia = t; }

void SepedaPinjam::tampilkan() const {
    Sepeda::tampilkan();
    cout << "Status: " << (tersedia ? "Ready" : "Dipinjam") << endl;
}
