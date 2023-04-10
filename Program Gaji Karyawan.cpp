//Created Program By 20220801379_Irfan Prayogi
//Teknik Informatika
//Program Gaji Karyawan

#include <iostream>
using namespace std;

struct gajikaryawan
{
    string nama_karyawan;
    int upah_perjam = 50000;
    int upah_lembur;
    int upah_lemburperjam;
    int gaji_lembur;
    int gaji_harian; 
    int jam_kerja;
};

int main() {
    char  loop;

 do{
    gajikaryawan gaji;
    
    cout << "\n\nCreated By 20220801379_Irfan Prayogi" << endl;
    cout << "\nMasukkan Nama Karyawan: ";
    getline (cin, gaji.nama_karyawan);
    cout << "\nMasukkan Jam Kerja: ";
    cin >> gaji.jam_kerja;
    
    //Operator
    if (gaji.jam_kerja > 7) {
        gaji.upah_lemburperjam = 15 * gaji.upah_perjam;
        gaji.upah_lembur = (gaji.jam_kerja - 7) * gaji.upah_lemburperjam;
        gaji.gaji_lembur = gaji.upah_perjam * gaji.jam_kerja + gaji.upah_lembur;
        cout << "\nNama : " << gaji.nama_karyawan;
        cout << "\nGaji Anda adalah Rp " << gaji.gaji_lembur;    
    }
    else {
        gaji.gaji_harian = gaji.upah_perjam*gaji.jam_kerja;
        cout << "\nNama : " << gaji.nama_karyawan;
        cout << "\nGaji Anda adalah Rp " << gaji.gaji_harian << endl;
    }
    
    cout << "\nApakah kamu ingin melanjutkan? (Y/N): ";
        cin >> loop;
        cin.ignore(); 
    } while (loop == 'y' || loop == 'Y');

    return 0;
}
