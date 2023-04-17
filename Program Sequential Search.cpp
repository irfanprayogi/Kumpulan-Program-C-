// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Sequential Search

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    int n, i, posisi, ditemukan;
    string input_nama;

    cout << "----Input dan Pencarian Nama Mahasiswa Esa Unggul----\n";
    cout << "\nBanyak nama mahasiswa : ";
    cin >> n;
    string namaMahasiswa[n];
    cin.ignore(1000, '\n');

    for (int i = 0; i < n; i++)
    {
        cout << "\nMasukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, namaMahasiswa[i]);
    }

    cout << "\n===========================================" << endl;
    cout << "\nNama mahasiswa yang akan dicari : ";
    getline(cin, input_nama);

    ditemukan == 0;
    i = 0;

    while ((ditemukan == 0) && (i < n))
    {
        if (namaMahasiswa[i] == input_nama)
        {
            ditemukan = 1;
            posisi = i;
        }
        else
            i = i + 1;
    }

    if (ditemukan == 1)
    {
        cout << "Ditemukan nama mahasiswa " << input_nama << " pada posisi " << posisi + 1;
    }
    else
    {
        cout << "Maaf tidak ditemukan mahasiswa bernama " << input_nama;
    }

    return 0;
}
