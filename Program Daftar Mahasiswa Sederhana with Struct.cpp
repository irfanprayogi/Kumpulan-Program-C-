//Created Program By 20220801379_Irfan Prayogi
//Teknik Informatika
//Program Daftar Mahasiswa Sederhana With Struct

#include <iostream>
using namespace std;

struct Alamat {
    string nama_jalan;
    int nomor_rumah;
};

struct TanggalLahir {
    int tanggal;
    int bulan;
    int tahun;
};


struct Mahasiswa {
    char nim [50];
    char nama [50];
    string tempat;
    Alamat alamat_mhs;
    TanggalLahir tgl_lahir;
};

int main () {
    int jumlah_mhs;
    
    cout << "Masukkan Jumlah Mahasiswa: ";
    cin >> jumlah_mhs;
    
    Mahasiswa mhs[jumlah_mhs];
   
    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "==============================";
        cout << "\nData mahasiswa ke-" << i+1 << endl;
        cout << "Masukkan Nim Anda: ";
        cin >> mhs[i].nim;
        cin.ignore(1000,'\n');
        cout << "Masukkan Nama Anda: ";
        cin.getline(mhs[i].nama, 20);
        cout << "Masukkan Alamat Anda: ";
        cout << "\nNama Jalan: ";
        getline (cin, mhs[i].alamat_mhs.nama_jalan);
        cout << "Nomor Rumah: ";
        cin >> mhs[i].alamat_mhs.nomor_rumah;
        cin.ignore(1000,'\n');
        cout << "Masukkan Tempat, Tanggal Lahir: ";
        cout << "\nTempat: ";
        getline (cin, mhs[i].tempat);
        cout << "Tanggal Lahir (DD/MM/YYYY: ";
        cout << "\nTanggal: ";
        cin >> mhs[i].tgl_lahir.tanggal;
        cout << "Bulan: ";
        cin >> mhs[i].tgl_lahir.bulan;
        cout << "Tahun: ";
        cin >> mhs[i].tgl_lahir.tahun;
    }

    cout << "\n=========== Menampilkan Hasil ===========" << endl;
    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "\nData Mahasiswa Ke-" << i+1;
        cout << "\nNim                      : " << mhs[i].nim;
        cout << "\nNama                     : " << mhs[i].nama;
        cout << "\nAlamat                   : " << mhs[i].alamat_mhs.nama_jalan << ", No." << mhs[i].alamat_mhs.nomor_rumah;
        cout << "\nTempat, Tanggal Lahir    : " << mhs[i].tempat << "," << mhs[i].tgl_lahir.tanggal << "/"<< "0" << mhs[i].tgl_lahir.bulan << "/" << mhs[i].tgl_lahir.tahun << endl;
    }
    
    cout << "\n============= Terima Kasih =============";
    
    return 0;
}