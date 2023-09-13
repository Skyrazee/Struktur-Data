#include <iostream>
#include <string>

const int MAX_DATA = 10;
const int ATTRIBUTES = 10;

// Deklarasi array 2D untuk menyimpan data
std::string data[MAX_DATA][ATTRIBUTES];
int data_count = 0;

// Fungsi untuk menampilkan data
void tampilkan_data() {
    if (data_count == 0) {
        std::cout << "Daftar kosong." << std::endl;
    } else {
        std::cout << "Data yang disimpan:" << std::endl;
        for (int i = 0; i < data_count; ++i) {
            std::cout << "Data ke-" << i + 1 << ": ";
            for (int j = 0; j < ATTRIBUTES; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

// Fungsi untuk menambah data baru
void tambah_data() {
    if (data_count < MAX_DATA) {
        std::cout << "Masukkan data baru (10 atribut):" << std::endl;
        for (int i = 0; i < ATTRIBUTES; ++i) {
            std::cout << "Atribut ke-" << i + 1 << ": ";
            std::cin >> data[data_count][i];
        }
        data_count++;
        std::cout << "Data berhasil ditambahkan." << std::endl;
    } else {
        std::cout << "Daftar penuh." << std::endl;
    }
}

// Fungsi untuk menghapus data
void hapus_data() {
    if (data_count == 0) {
        std::cout << "Daftar kosong. Tidak ada data untuk dihapus." << std::endl;
    } else {
        std::cout << "Masukkan nomor data yang akan dihapus (1-" << data_count << "): ";
        int nomor;
        std::cin >> nomor;

        if (nomor >= 1 && nomor <= data_count) {
            for (int i = nomor - 1; i < data_count - 1; ++i) {
                for (int j = 0; j < ATTRIBUTES; ++j) {
                    data[i][j] = data[i + 1][j];
                }
            }
            data_count--;
            std::cout << "Data berhasil dihapus." << std::endl;
        } else {
            std::cout << "Nomor data tidak valid." << std::endl;
        }
    }
}

// Fungsi untuk mengubah data
void ubah_data() {
    if (data_count == 0) {
        std::cout << "Daftar kosong. Tidak ada data untuk diubah." << std::endl;
    } else {
        std::cout << "Masukkan nomor data yang akan diubah (1-" << data_count << "): ";
        int nomor;
        std::cin >> nomor;

        if (nomor >= 1 && nomor <= data_count) {
            std::cout << "Masukkan data baru (10 atribut):" << std::endl;
            for (int i = 0; i < ATTRIBUTES; ++i) {
                std::cout << "Atribut ke-" << i + 1 << ": ";
                std::cin >> data[nomor - 1][i];
            }
            std::cout << "Data berhasil diubah." << std::endl;
        } else {
            std::cout << "Nomor data tidak valid." << std::endl;
        }
    }
}

// Fungsi untuk mencari data
void cari_data() {
    if (data_count == 0) {
        std::cout << "Daftar kosong. Tidak ada data untuk dicari." << std::endl;
    } else {
        std::cout << "Masukkan data yang ingin dicari (10 atribut):" << std::endl;
        std::string pencarian[ATTRIBUTES];
        for (int i = 0; i < ATTRIBUTES; ++i) {
            std::cout << "Atribut ke-" << i + 1 << ": ";
            std::cin >> pencarian[i];
        }
        bool ditemukan = false;

        for (int i = 0; i < data_count; ++i) {
            bool cocok = true;
            for (int j = 0; j < ATTRIBUTES; ++j) {
                if (data[i][j] != pencarian[j]) {
                    cocok = false;
                    break;
                }
            }
            if (cocok) {
                std::cout << "Data ditemukan pada indeks " << i + 1 << std::endl;
                ditemukan = true;
            }
        }

        if (!ditemukan) {
            std::cout << "Data tidak ditemukan." << std::endl;
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        std::cout << "Pilihan Menu:" << std::endl;
        std::cout << "1. Tampilkan Data" << std::endl;
        std::cout << "2. Tambah Data" << std::endl;
        std::cout << "3. Hapus Data" << std::endl;
        std::cout << "4. Ubah Data" << std::endl;
        std::cout << "5. Cari Data" << std::endl;
        std::cout << "6. Keluar" << std::endl;
        std::cout << "Pilih menu (1-6): ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkan_data();
                break;
            case 2:
                tambah_data();
                break;
            case 3:
                hapus_data();
                break;
            case 4:
                ubah_data();
                break;
            case 5:
                cari_data();
                break;
            case 6:
                std::cout << "Terima kasih. Program telah selesai." << std::endl;
                return 0;
            default:
                std::cout << "Pilihan tidak valid. Cobalah memilih menu (1-6)." << std::endl;
                break;
        }
    }

    return 0;
}

