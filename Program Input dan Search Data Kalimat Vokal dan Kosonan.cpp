// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Input dan Search Data Kalimat Vokal dan Kosonan

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char kalimat[100];
    int vokal = 0;
    int konsonan = 0;
    int numerik = 0;
    int n, i, ditemukan, posisi;
    char data;

    cout << "\nInput: ";
    cin.getline(kalimat, 100);

    char huruf_vkl[strlen(kalimat)];
    char huruf_kskn[strlen(kalimat)];
    int angka[strlen(kalimat)];

    int v = 0, k = 0;

    for (int i = 0; i < strlen(kalimat); i++)
    {
        if ((kalimat[i] >= 'a' && kalimat[i] <= 'z') || (kalimat[i] >= 'A' && kalimat[i] <= 'Z'))
        {
            if (kalimat[i] == 'a' || kalimat[i] == 'e' || kalimat[i] == 'i' || kalimat[i] == 'o' || kalimat[i] == 'u' || kalimat[i] == 'A' || kalimat[i] == 'E' || kalimat[i] == 'I' || kalimat[i] == 'O' || kalimat[i] == 'U')
            {
                vokal++;
                huruf_vkl[v] = kalimat[i];
                v++;
            }
            else
            {
                konsonan++;
                huruf_kskn[k] = kalimat[i];
                k++;
            }
        }
        else if (kalimat[i] >= '0' && kalimat[i] <= '9')
        {
            numerik++;
            angka[n] = kalimat[i] - '0';
            n++;
        }
    }

    cout << "Output : " << endl;
    cout << "Vokal = " << vokal << " = ";
    for (int i = 0; i < v; i++)
    {
        cout << huruf_vkl[i] << " ";
    };
    cout << endl;

    cout << "Konsonan = " << konsonan << " = ";
    for (int i = 0; i < k; i++)
    {
        cout << huruf_kskn[i] << " ";
    };
    cout << endl;

    cout << "Numerik = " << numerik << " = ";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    };
    cout << endl;

    cout << "Masukkan data yang akan Anda cari: ";
    cin >> data;

    for (int i = 0; i < strlen(kalimat); i++)
    {
        if (data == kalimat[i])
        {
            ditemukan = 1;
        }
        else
            i = i + 1;
    }

    if (ditemukan == 1)
    {
        cout << "\nData " << data << " Ada";
    }
    else
    {
        cout << "\nData tidak... " << data;
    }

    return 0;
}
