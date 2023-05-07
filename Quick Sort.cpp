// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Quick Sort

#include <iostream>
using namespace std;

int partition(int data[], int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i+1], data[high]);
    return i+1;
}

void quickSort(int data[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(data, low, high);
        quickSort(data, low, pivotIndex-1);
        quickSort(data, pivotIndex+1, high);
    }
}

int main() {
    int data[6];
    cout << "Program Quick Sort" << endl;
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

    quickSort(data, 0, n-1);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}