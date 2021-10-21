#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int a[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
                swap(a[min_index], a[i]);
            }
        }
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
    selectionSort(a, n);
    printArray(a, n);
}
