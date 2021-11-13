#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void permutation(string a, int left, int right) {
    if (left == right) {
        cout << a << endl;
    } else {
        for (int i = left; i <= right; i++)
        {
            swap(a[left], a[i]);
            permutation(a, left + 1, right);
            swap(a[left], a[i]);
        }
    }
}
int main() {
    int n;
    cin >> n;
    string str = "";
    for (int i = 1; i <= n; i++) {
        str = str + to_string(i);
    }
    permutation(str, 0, str.size() - 1);
    return 0;
}
