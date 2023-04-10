//Created Program By 20220801379_Irfan Prayogi
//Teknik Informatika
//Program Struct Input Kartu Tanda Mahasiswa

#include <iostream>
using namespace std;

struct Alamat {
    string nama_jalan;
    int nomor_rumah;
    string kota;
    string provinsi;
};

struct TanggalLahir {
    int tanggal;
    string bulan;
    int tahun;
};


struct Mahasiswa {
    long long nim;
    char nama [50];
    string tempat;
    Alamat alamat_mhs;
    TanggalLahir tgl_lahir;
};

int main () {
    
    Mahasiswa m;

        cout << "\n\nCreated By 20220801379_Irfan Prayogi" << endl;
        cout << "\nSelamat Datang di Program Input KTM";
        cout << "\nMasukan Nim Anda: ";
        cin >> m.nim;
        cin.ignore(1000,'\n');
        cout << "\nMasukan Nama Anda: ";
        cin.getline(m.nama, 20);
        cout << "\nMasukan Alamat Anda: ";
        cout << "\nNama Jalan: ";
        getline (cin, m.alamat_mhs.nama_jalan);
        cout << "\nNomor Rumah: ";
        cin >> m.alamat_mhs.nomor_rumah;
        cout << "\nKota: ";
        cin.ignore(1000,'\n');
        getline (cin, m.alamat_mhs.kota);
        cout << "\nProvinsi: ";
        getline (cin, m.alamat_mhs.provinsi);
        cout << "\nMasukan Tempat, Tanggal Lahir: ";
        cout << "\nTempat: ";
        getline (cin, m.tempat);
        cout << "\nTanggal Lahir: ";
        cout << "\nTanggal: ";
        cin >> m.tgl_lahir.tanggal;
        cout << "\nBulan: ";
        cin >> m.tgl_lahir.bulan;
        cout << "\nTahun: ";
        cin >> m.tgl_lahir.tahun;
    
    
    cout << endl;
    cout << "\n\n------Menampilkan Hasil------" << endl;
        cout << "\nNim                      : " << m.nim;
        cout << "\nNama                     : " << m.nama;
        cout << "\nAlamat                   : " << m.alamat_mhs.nama_jalan << ", No." << m.alamat_mhs.nomor_rumah << ", " << m.alamat_mhs.kota << ", " << m.alamat_mhs.provinsi;
        cout << "\nTempat, Tanggal Lahir    : " << m.tempat << "," << m.tgl_lahir.tanggal << " "<< m.tgl_lahir.bulan << " " << m.tgl_lahir.tahun << endl;
    
    return 0;
}
