// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Selection Sort

#include <iostream>
using namespace std;

void selectionSort(int data[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
}

int main() {
    int data[6];
    cout << "Program Selection Sort" << endl;
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

    selectionSort(data, n);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}