#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "../model/SepedaJual.h"
#include "../model/SepedaPinjam.h"
#include <vector>
using namespace std;

class FileManager {
public:
    static void simpanSepedaJual(const vector<SepedaJual>& list);
    static void simpanSepedaPinjam(const vector<SepedaPinjam>& list);
    static vector<SepedaJual> loadSepedaJual();
    static vector<SepedaPinjam> loadSepedaPinjam();
};
#endif
