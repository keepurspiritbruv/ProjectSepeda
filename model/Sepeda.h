#ifndef SEPEDA_H
#define SEPEDA_H
#include <string>
using namespace std;

class Sepeda {
protected:
    string merk;
    string kondisi;
    int harga;
public:
    Sepeda(string m = "", string k = "", int h = 0);
    virtual void tampilkan() const;
    string getMerk() const;
    string getKondisi() const;
    int getHarga() const;
    void setMerk(const string& m);
    void setKondisi(const string& k);
    void setHarga(int h);
};
#endif
