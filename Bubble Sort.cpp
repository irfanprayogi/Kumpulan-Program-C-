// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Bubble Sort

#include <iostream>
using namespace std;

void bubbleSort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

int main() {
    int data[6];
    cout << "Program Bubble Sort" << endl;
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

    bubbleSort(data, n);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
