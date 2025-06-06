#include "../manager/SepedaManager.h"
#include "../manager/FileManager.h"
#include "../model/SepedaJual.h"
#include "../model/SepedaPinjam.h"
#include <iostream>
#include <vector>
using namespace std;

void SepedaManager::menuUtama() {
    int pilihan;
    do {
        cout << "\n=== Aplikasi Sepeda ===\n";
        cout << "1. Jual Sepeda\n2. Beli Sepeda\n3. Pinjam Sepeda\n4. Tambah Sepeda Pinjam\n5. Edit Sepeda Jual\n6. Hapus Sepeda Jual\n7. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            case 1: jualSepeda(); break;
            case 2: beliSepeda(); break;
            case 3: pinjamSepeda(); break;
            case 4: tambahSepedaPinjam(); break;
            case 5: editSepeda(); break;
            case 6: hapusSepeda(); break;
            case 7: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);
}

void SepedaManager::jualSepeda() {
    string merk, kondisi;
    int harga;
    cin.ignore();
    cout << "Merk: "; getline(cin, merk);
    cout << "Kondisi: "; getline(cin, kondisi);
    cout << "Harga: "; cin >> harga;
    auto list = FileManager::loadSepedaJual();
    list.emplace_back(merk, kondisi, harga);
    FileManager::simpanSepedaJual(list);
    cout << "Sepeda berhasil ditambahkan untuk dijual!\n";
}

void SepedaManager::beliSepeda() {
    auto list = FileManager::loadSepedaJual();
    if (list.empty()) {
        cout << "Tidak ada sepeda yang dijual.\n";
        return;
    }
    cout << "\n=== Daftar Sepeda Dijual ===\n";
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i+1 << ". ";
        list[i].tampilkan();
    }
    int pilih;
    cout << "Pilih nomor sepeda yang ingin dibeli (0 untuk batal): ";
    cin >> pilih;
    if (pilih > 0 && pilih <= (int)list.size()) {
        list.erase(list.begin() + pilih - 1);
        FileManager::simpanSepedaJual(list);
        cout << "Transaksi pembelian berhasil.\n";
    }
}

void SepedaManager::pinjamSepeda() {
    auto list = FileManager::loadSepedaPinjam();
    bool found = false;
    for (auto& s : list) {
        if (s.isTersedia()) {
            s.tampilkan();
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada sepeda yang tersedia.\n";
        return;
    }
    string merk;
    cin.ignore();
    cout << "Masukkan merk sepeda yang ingin dipinjam: ";
    getline(cin, merk);
    for (auto& s : list) {
        if (s.getMerk() == merk && s.isTersedia()) {
            s.setTersedia(false);
            FileManager::simpanSepedaPinjam(list);
            cout << "Sepeda berhasil dipinjam.\n";
            return;
        }
    }
    cout << "Sepeda tidak ditemukan atau sudah dipinjam.\n";
}

void SepedaManager::tambahSepedaPinjam() {
    string merk, kondisi;
    int harga;
    cin.ignore();
    cout << "Merk: "; getline(cin, merk);
    cout << "Kondisi: "; getline(cin, kondisi);
    cout << "Harga: "; cin >> harga;
    auto list = FileManager::loadSepedaPinjam();
    list.emplace_back(merk, kondisi, harga, true);
    FileManager::simpanSepedaPinjam(list);
    cout << "Sepeda berhasil ditambahkan untuk dipinjamkan!\n";
}

void SepedaManager::editSepeda() {
    auto list = FileManager::loadSepedaJual();
    if (list.empty()) {
        cout << "Tidak ada sepeda untuk diedit.\n";
        return;
    }
    int idx;
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i+1 << ". ";
        list[i].tampilkan();
    }
    cout << "Pilih nomor sepeda yang ingin diedit: ";
    cin >> idx;
    if (idx < 1 || idx > (int)list.size()) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    string merk, kondisi;
    int harga;
    cin.ignore();
    cout << "Merk baru: "; getline(cin, merk);
    cout << "Kondisi baru: "; getline(cin, kondisi);
    cout << "Harga baru: "; cin >> harga;
    list[idx-1].setMerk(merk);
    list[idx-1].setKondisi(kondisi);
    list[idx-1].setHarga(harga);
    FileManager::simpanSepedaJual(list);
    cout << "Data sepeda berhasil diperbarui.\n";
}

void SepedaManager::hapusSepeda() {
    auto list = FileManager::loadSepedaJual();
    if (list.empty()) {
        cout << "Tidak ada sepeda untuk dihapus.\n";
        return;
    }
    int idx;
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i+1 << ". ";
        list[i].tampilkan();
    }
    cout << "Pilih nomor sepeda yang ingin dihapus: ";
    cin >> idx;
    if (idx < 1 || idx > (int)list.size()) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    list.erase(list.begin() + idx - 1);
    FileManager::simpanSepedaJual(list);
    cout << "Data sepeda berhasil dihapus.\n";
}
