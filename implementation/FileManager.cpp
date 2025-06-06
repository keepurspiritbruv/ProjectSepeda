#include "../manager/FileManager.h"
#include <fstream>
#include <sstream>

void FileManager::simpanSepedaJual(const vector<SepedaJual>& list) {
    ofstream file("jual.txt");
    for (const auto& s : list) {
        file << s.getMerk() << "," << s.getKondisi() << "," << s.getHarga() << endl;
    }
}

void FileManager::simpanSepedaPinjam(const vector<SepedaPinjam>& list) {
    ofstream file("pinjam.txt");
    for (const auto& s : list) {
        file << s.getMerk() << "," << s.getKondisi() << "," << s.getHarga() << "," << s.isTersedia() << endl;
    }
}

vector<SepedaJual> FileManager::loadSepedaJual() {
    vector<SepedaJual> list;
    ifstream file("jual.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string merk, kondisi;
        int harga;
        getline(ss, merk, ',');
        getline(ss, kondisi, ',');
        ss >> harga;
        list.emplace_back(merk, kondisi, harga);
    }
    return list;
}

vector<SepedaPinjam> FileManager::loadSepedaPinjam() {
    vector<SepedaPinjam> list;
    ifstream file("pinjam.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string merk, kondisi;
        int harga, status;
        getline(ss, merk, ',');
        getline(ss, kondisi, ',');
        ss >> harga;
        ss.ignore();
        ss >> status;
        list.emplace_back(merk, kondisi, harga, status == 1);
    }
    return list;
}
