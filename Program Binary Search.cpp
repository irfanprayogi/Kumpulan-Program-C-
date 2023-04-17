// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Binary Search

#include <iostream>
#include <string>
using namespace std;

int binarySearch(string nama[], int low, int high, string input)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nama[mid] == input)
            return mid;
        else if (nama[mid] < input)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // elemen tidak ditemukan
}

int main()
{
    string nama[] = {"Budi Sandoyo", "Irfan Prayogi", "Jaja Suharja", "Naruto Uzumaki", "Sasuka Susanto"};
    int n = sizeof(nama) / sizeof(nama[0]);

    cout << "\n---Pencarian Nama Mahasiswa Esa Unggul--- " << endl;
    string input;
    cout << "Masukkan nama yang ingin dicari: ";
    getline(cin, input);

    cout << "\n=======================================";
    int result = binarySearch(nama, 0, n - 1, input);
    if (result == -1)
    {
        cout << "\nMaaf,Nama " << input << " Tidak ditemukan! " << endl;
    }
    else
    {
        cout << "\nNama " << input << " ditemukan pada posisi ke-" << result << endl;
    }
    return 0;
}