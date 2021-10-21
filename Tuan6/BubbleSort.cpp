#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int a[], int n) {
    int i, j;
    bool swaped = false;
    for (i = 0; i < n-1; i++) {
        swaped = false;
        for (j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swaped = true;
            }
        }
        if (swaped == false) break;
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

    bubbleSort(a, n);

    printArray(a, n);
    return 0;
}
