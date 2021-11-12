#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return (b, a % b);
}

int main () {
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    cout << gcd(a, b);
    return 0;
}
