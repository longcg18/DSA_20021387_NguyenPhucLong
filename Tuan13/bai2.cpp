#include <iostream>
#include <algorithm>
using namespace std;


int main () {

    int n, X;
    cin >> n >> X;


    int a[n];

    for (int i = 0; i < n; i++)  cin >> a[i];

    sort(a, a+n);

    for (int i = 0; i < n; i++) {

        int sum = 0;
        int j = i;
        while(sum < X && j < n) {
            sum += a[j];
            j++;
            if (sum == X) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 1;
}
