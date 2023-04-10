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
    const int jumlah_mhs = 5;
    Mahasiswa m[jumlah_mhs];
   
    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i+1 << endl;
        cout << "\nMasukan Nim Anda: ";
        cin >> m[i].nim;
        cin.ignore(1000,'\n');
        cout << "\nMasukan Nama Anda: ";
        cin.getline(m[i].nama, 20);
        cout << "\nMasukan Alamat Anda: ";
        cout << "\nNama Jalan: ";
        getline (cin, m[i].alamat_mhs.nama_jalan);
        cout << "\nNomor Rumah: ";
        cin >> m[i].alamat_mhs.nomor_rumah;
        cout << "\nKota: ";
        cin.ignore(1000,'\n');
        getline (cin, m[i].alamat_mhs.kota);
        cout << "\nProvinsi: ";
        getline (cin, m[i].alamat_mhs.provinsi);
        cout << "\nMasukan Tempat, Tanggal Lahir: ";
        cout << "\nTempat: ";
        getline (cin, m[i].tempat);
        cout << "\nTanggal Lahir: ";
        cout << "\nTanggal: ";
        cin >> m[i].tgl_lahir.tanggal;
        cout << "\nBulan: ";
        cin >> m[i].tgl_lahir.bulan;
        cout << "\nTahun: ";
        cin >> m[i].tgl_lahir.tahun;
    }
    
    cout << endl;
    cout << "\n\n------Menampilkan Hasil------" << endl;
    for (int i = 0; i < jumlah_mhs; i++) {
        cout << "\nKartu Tanda Mahasiswa Ke-" << i+1;
        cout << "\nNim                      : " << m[i].nim;
        cout << "\nNama                     : " << m[i].nama;
        cout << "\nAlamat                   : " << m[i].alamat_mhs.nama_jalan << ", No." << m[i].alamat_mhs.nomor_rumah << ", " << m[i].alamat_mhs.kota << ", " << m[i].alamat_mhs.provinsi;
        cout << "\nTempat, Tanggal Lahir    : " << m[i].tempat << "," << m[i].tgl_lahir.tanggal << " "<< m[i].tgl_lahir.bulan << " " << m[i].tgl_lahir.tahun << endl;
    }
    
    return 0;
}
