#ifndef SEPEDAPINJAM_H
#define SEPEDAPINJAM_H
#include "Sepeda.h"

class SepedaPinjam : public Sepeda {
    bool tersedia;
public:
    SepedaPinjam(string m = "", string k = "", int h = 0, bool t = true);
    void tampilkan() const override;
    bool isTersedia() const;
    void setTersedia(bool t);
};
#endif
