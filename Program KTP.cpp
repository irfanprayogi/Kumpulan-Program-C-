#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct
{
    int tgl;
    int bln;
    int th;
} Tanggal;
typedef struct
{
    char noID[5];
    char nama[30];
    char jenis_kelamin; // ’L’ atau ‘P’
    Tanggal t;
} KTP;
typedef struct
{
    KTP ktp;
    int jml;
} Data_KTP;
Data_KTP data_ktp;
Data_KTP *p = &data_ktp;

int main()
{
    char ulang;

    do
    {
        // MENU FUNGSI
        int pilih_fungsi;
        cout << "========== Menu Utama ==========" << endl;
        cout << "1. Menambah data" << endl;
        cout << "2. Mencari data" << endl;
        cout << "3. Menampilkan data" << endl;
        cout << "4. Mengedit data" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilih_fungsi;
        cout << endl;

        // Jika Input 1 Maka Masuk Menu Menambah Data
        if (pilih_fungsi == 1)
        {
            cout << "-----Menu Menambah data------" << endl;

            if (data_ktp.jml == 0)
            {
                cout << "Masukkan jumlah data yang ingin ditambahkan: ";
                cin >> data_ktp.jml;
                p = new Data_KTP[data_ktp.jml];
                for (int i = 0; i < data_ktp.jml; i++)
                {
                    cout << "-------------------" << endl;
                    cout << "Masukkan data ke-" << i + 1 << endl;
                    cout << "Nomor ID: ";
                    cin >> p[i].ktp.noID, 5;
                    cout << "Nama Lengkap: ";
                    cin.ignore(1000, '\n');
                    cin.getline(p[i].ktp.nama, 30);
                    cout << "Jenis Kelamin (L/P) : ";
                    cin >> p[i].ktp.jenis_kelamin;
                    cout << "Tanggal Lahir : ";
                    cout << "\nTanggal : ";
                    cin >> p[i].ktp.t.tgl;
                    cout << "Bulan : ";
                    cin >> p[i].ktp.t.bln;
                    cout << "Tahun : ";
                    cin >> p[i].ktp.t.th;
                }
            }
            else
            {
                cout << "Masukkan data yang ingin ditambahkan1: ";
                Data_KTP *p_new;
                p_new = new Data_KTP[data_ktp.jml + 1];

                for (int i = 0; i < data_ktp.jml; i++)
                {
                    p_new[i] = p[i];
                }

                delete[] p;
                p = p_new;

                cout << "-------------------" << endl;
                cout << "Nomor ID: ";
                cin >> p[data_ktp.jml].ktp.noID, 5;
                cout << "Nama Lengkap: ";
                cin.ignore(1000, '\n');
                cin.getline(p[data_ktp.jml].ktp.nama, 30);
                cout << "Jenis Kelamin (L/P) : ";
                cin >> p[data_ktp.jml].ktp.jenis_kelamin;
                cout << "Tanggal Lahir : ";
                cout << "\nTanggal : ";
                cin >> p[data_ktp.jml].ktp.t.tgl;
                cout << "Bulan : ";
                cin >> p[data_ktp.jml].ktp.t.bln;
                cout << "Tahun : ";
                cin >> p[data_ktp.jml].ktp.t.th;
                data_ktp.jml++;
            }

            for (int i = 0; i < data_ktp.jml; i++)
            {
                cout << "-----------------------------" << endl;
                cout << "No. ID         : " << p[i].ktp.noID << endl;
                cout << "Nama Lengkap   : " << p[i].ktp.nama << endl;
                cout << "Jenis Kelamin  : " << p[i].ktp.jenis_kelamin << endl;
                cout << "Tanggal Lahir  : " << p[i].ktp.t.tgl << "/" << p[i].ktp.t.bln << "/" << p[i].ktp.t.th << endl;
            }
            cout << endl;
        }
        // Jika Input 2 Maka Masuk Menu Mencari data berdasarkan tahun kelahiran
        else if (pilih_fungsi == 2)
        {
            int cari_th;
            int ditemukan;
            cout << "\n-----Menu Mencari data ------" << endl;
            cout << "Masukkan tahun kelahiran yang dicari: ";
            cin >> cari_th;

            ditemukan = 0;

            for (int i = 0; i < data_ktp.jml; i++)
            {
                if (p[i].ktp.t.th == cari_th)
                {
                    cout << "\nMenampilkan data berdasarkan kelahiran " << cari_th << endl;
                    cout << "-----------------------------" << endl;
                    cout << "No. ID         : " << p[i].ktp.noID << endl;
                    cout << "Nama Lengkap   : " << p[i].ktp.nama << endl;
                    cout << "Jenis Kelamin  : " << p[i].ktp.jenis_kelamin << endl;
                    cout << "Tanggal Lahir  : " << p[i].ktp.t.tgl << "/" << p[i].ktp.t.bln << "/" << p[i].ktp.t.th << endl;
                    cout << endl;
                    ditemukan = 1;
                }
            }

            if (ditemukan == 0)
            {
                cout << "Data tidak ditemukan" << endl;
            }
        }
        // Jika Input 3 Maka Masuk Menu Menampilkan data berdasarkan jenis kelamin
        else if (pilih_fungsi == 3)
        {
            char jeniskelaminL = 'L';
            char jeniskelaminP = 'P';
            cout << "-----Menu Menampilkan data ------" << endl;

            for (int i = 0; i < data_ktp.jml; i++)
            {
                if (p[i].ktp.jenis_kelamin == jeniskelaminL)
                {
                    cout << "Berdasarkan jenis kelamin laki-laki" << endl;
                    cout << "----------------------------------" << endl;
                    cout << "No. ID         : " << p[i].ktp.noID << endl;
                    cout << "Nama Lengkap   : " << p[i].ktp.nama << endl;
                    cout << "Jenis Kelamin  : " << p[i].ktp.jenis_kelamin << endl;
                    cout << "Tanggal Lahir  : " << p[i].ktp.t.tgl << "/" << p[i].ktp.t.bln << "/" << p[i].ktp.t.th << endl;
                }
                else if (p[i].ktp.jenis_kelamin == jeniskelaminP)
                {
                    cout << "Berdasarkan jenis kelamin perempuan" << endl;
                    cout << "----------------------------------" << endl;
                    cout << "No. ID         : " << p[i].ktp.noID << endl;
                    cout << "Nama Lengkap   : " << p[i].ktp.nama << endl;
                    cout << "Jenis Kelamin  : " << p[i].ktp.jenis_kelamin << endl;
                    cout << "Tanggal Lahir  : " << p[i].ktp.t.tgl << "/" << p[i].ktp.t.bln << "/" << p[i].ktp.t.th << endl;
                }
            }
        }
        // Jika Input 4 Maka Masuk Menu Mengedit data
        else if (pilih_fungsi == 4)
        {

            char NoID[5];

            cout << "-----Menu Mengedit data ------" << endl;
            cout << "Masukkan Nomor ID data yang akan diubah : ";
            cin >> NoID;
            bool ditemukan = false;
            int index;

            for (int i = 0; i < data_ktp.jml; i++)
            {
                if (strcmp(p[i].ktp.noID, NoID) == 0)
                {
                    ditemukan = true;
                    index = i;
                    break;
                }
            }

            if (ditemukan)
            {
                cout << "Masukkan data yang baru : " << endl;
                cout << "Nomor ID: ";
                cin >> p[index].ktp.noID, 5;
                cout << "Nama Lengkap: ";
                cin.ignore(1000, '\n');
                cin.getline(p[index].ktp.nama, 30);
                cout << "Jenis Kelamin (L/P) : ";
                cin >> p[index].ktp.jenis_kelamin;
                cout << "Tanggal Lahir : ";
                cout << "\nTanggal : ";
                cin >> p[index].ktp.t.tgl;
                cout << "Bulan : ";
                cin >> p[index].ktp.t.bln;
                cout << "Tahun : ";
                cin >> p[index].ktp.t.th;

                cout << "Data berhasil diubah." << endl;
            }
            else
            {
                cout << "Data dengan Nomor ID tersebut tidak ditemukan." << endl;
            }
        }
        cout << "Apakah ingin mengulang lagi? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}