// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Insertion Sort

#include <iostream>
using namespace std;

void insertionSort(int data[], int n) {
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

int main() {
    int data[6];
    cout << "Program Insertion Sort" << endl;
    for (int i=0; i < 6; i++) {
        cout << "Input Data Ke-" << i+1 << ": ";
        cin >> data[i];
    }
    
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    insertionSort(data, n);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}