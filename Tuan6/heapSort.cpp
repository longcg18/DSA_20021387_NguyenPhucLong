#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    heapSort(a, n);

    printArray(a, n);
    return 0;
}
