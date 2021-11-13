#include <iostream>
using namespace std;

void printArray(int a[], int n) {

    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void generateBinary(int n, int a[], int i) {
    if (i == n) {
        printArray(a, n);
        return;
    }
    a[i] = 0;
    generateBinary(n, a, i+1);
    a[i] = 1;
    generateBinary(n, a, i+1);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    generateBinary(n, a, 0);
    return 0;
}
