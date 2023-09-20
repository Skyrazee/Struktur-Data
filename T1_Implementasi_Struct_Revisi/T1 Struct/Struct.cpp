#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Deklarasi struktur data
struct Data {
    string nama;
    int nrp;
};

// Fungsi untuk menampilkan data
void tampilkanData(const vector<Data>& data) {
    cout << "Data:" << endl;
    for (const Data& d : data) {
        cout << "Nama: " << d.nama << ", 2 digit belakang NRP: " << d.nrp << endl;
    }
    cout << endl;
}

int main() {
    vector<Data> data;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data Baru" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data);
                break;
            case 2: {
                Data newData;
                cout << "Masukkan Nama: ";
                cin >> newData.nama;
                cout << "Masukkan 2 digit belakang NRP: ";
                cin >> newData.nrp;
                data.push_back(newData);
                cout << "Data berhasil ditambahkan." << endl;
                break;
            }
            case 3: {
                if (data.empty()) {
                    cout << "Tidak ada data yang bisa dihapus." << endl;
                } else {
                    int indeks;
                    cout << "Masukkan indeks data yang akan dihapus: ";
                    cin >> indeks;
                    if (indeks >= 0 && indeks < data.size()) {
                        data.erase(data.begin() + indeks);
                        cout << "Data berhasil dihapus." << endl;
                    } else {
                        cout << "Indeks Salah." << endl;
                    }
                }
                break;
            }
            case 4: {
                if (data.empty()) {
                    cout << "Tidak ada data yang bisa diubah." << endl;
                } else {
                    int indeks;
                    cout << "Masukkan indeks data yang akan diubah: ";
                    cin >> indeks;
                    if (indeks >= 0 && indeks < data.size()) {
                        Data newData;
                        cout << "Masukkan Nama baru: ";
                        cin >> newData.nama;
                        cout << "Masukkan  2 digit belakang NRP baru: ";
                        cin >> newData.nrp;
                        data[indeks] = newData;
                        cout << "Data berhasil diubah." << endl;
                    } else {
                        cout << "Indeks Salah." << endl;
                    }
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Pilihan Salah." << endl;
                break;
        }
    }

    return 0;
}
