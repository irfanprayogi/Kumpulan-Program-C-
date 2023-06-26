// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Operasi Queue

#include <iostream>
#include <queue>
#include <climits>
#define MAX 4

using namespace std;

struct Queue
{
    int head;
    int tail;
    int data[MAX];
} Q;

int isFull()
{
    if (Q.tail == MAX)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (Q.tail == 0 & Q.head == 0)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue()
{
    int value;
    if (isFull())
    {
        cout << "Antrian Queue Penuh" << endl;
    }

    else
    {
        cout << "Masukkan Data: ";
        cin >> value;

        Q.data[Q.tail] = value;
        Q.tail++;
        Q.head = 0;
        cout << "Data " << value << " berhasil dimasukkan" << endl;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        cout << "Mengambil data " << Q.data[Q.head] << " dari antrian" << endl;

        for (int i = Q.head; i <= Q.tail; i++)
        {
            Q.data[i] = Q.data[i + 1];
        }
        Q.tail--;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        Q.head = 0;
        Q.tail = 0;
        cout << "Semua data telah dihapus" << endl;
    }
}

void print()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        cout << "Queue Antrian: ";
        for (int i = Q.head; i < Q.tail; i++)
        {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    }
}

void calculateTotal()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        int total = 0;
        for (int i = Q.head; i < Q.tail; i++)
        {
            total += Q.data[i];
        }
        cout << "Total: " << total << endl;
    }
}

void calculateAverage()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        int total = 0;
        int count = Q.tail - Q.head;
        for (int i = Q.head; i < Q.tail; i++)
        {
            total += Q.data[i];
        }
        double average = static_cast<double>(total) / count;
        cout << "Rata-rata: " << average << endl;
    }
}

void findMinValue()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        int minVal = INT_MAX;
        for (int i = Q.head; i < Q.tail; i++)
        {
            if (Q.data[i] < minVal)
            {
                minVal = Q.data[i];
            }
        }
        cout << "Nilai Terkecil: " << minVal << endl;
    }
}

void findMaxValue()
{
    if (isEmpty())
    {
        cout << "Antrian Queue Kosong" << endl;
    }
    else
    {
        int maxVal = INT_MIN;
        for (int i = Q.head; i < Q.tail; i++)
        {
            if (Q.data[i] > maxVal)
            {
                maxVal = Q.data[i];
            }
        }
        cout << "Nilai Terbesar: " << maxVal << endl;
    }
}

int main()
{
    int pilih;

    do
    {
        cout << "=====================" << endl;
        cout << "Menu Operasi Queue" << endl;
        cout << "by fnprygi" << endl;
        cout << "=====================" << endl;
        cout << "1.\tPush" << endl;
        cout << "2.\tPop" << endl;
        cout << "3.\tClear" << endl;
        cout << "4.\tPrint" << endl;
        cout << "5.\tHitung Total" << endl;
        cout << "6.\tRata-Rata" << endl;
        cout << "7.\tMin Data" << endl;
        cout << "8.\tMax Data" << endl;
        cout << "9.\tExit" << endl;
        cout << "=====================" << endl;
        cout << "Pilih Menu: ";
        cin >> pilih;
        cout << "=====================" << endl;

        if (pilih == 1)
        {
            enqueue();
        }
        else if (pilih == 2)
        {
            dequeue();
        }
        else if (pilih == 3)
        {
            clear();
        }
        else if (pilih == 4)
        {
            print();
        }
        else if (pilih == 5)
        {
            calculateTotal();
        }
        else if (pilih == 6)
        {
            calculateAverage();
        }
        else if (pilih == 7)
        {
            findMinValue();
        }
        else if (pilih == 8)
        {
            findMaxValue();
        }
        else if (pilih == 9)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Pilihan tidak ada, Silakan coba lagi!" << endl;
        }
        cout << endl;
    } while (pilih != 9);

    return 0;
}