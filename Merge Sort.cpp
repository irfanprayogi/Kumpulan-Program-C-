// Created Program By 20220801379_Irfan Prayogi
// Teknik Informatika
// Program Merge Sort

#include <iostream>
using namespace std;

void merge(int data[], int kiri, int mid, int kanan) {
    int n1 = mid - kiri + 1;
    int n2 = kanan - mid;
    int kiridata[n1], kanandata[n2];
    for (int i = 0; i < n1; i++) {
        kiridata[i] = data[kiri+i];
    }
    for (int j = 0; j < n2; j++) {
        kanandata[j] = data[mid+1+j];
    }
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (kiridata[i] <= kanandata[j]) {
            data[k] = kiridata[i];
            i++;
        } else {
            data[k] = kanandata[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = kiridata[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = kanandata[j];
        j++;
        k++;
    }
}

void mergeSort(int data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int mid = kiri + (kanan - kiri) / 2;
        mergeSort(data, kiri, mid);
        mergeSort(data, mid+1, kanan);
        merge(data, kiri, mid, kanan);
    }
}

int main() {
    int data[6];
    cout << "Program Merge Sort" << endl;
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

    mergeSort(data, 0, n-1);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}