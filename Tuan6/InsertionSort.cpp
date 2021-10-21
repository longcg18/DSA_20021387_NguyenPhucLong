#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[i] > key) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main () {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    int a[1000];
    cout << "Nhap " << n << " phan tu:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insertionSort(a, n);

    printArray(a, n);
    return 0;
}
