#include <iostream>
#include <cmath>

using namespace std;

int lcs_recursive(string s1, string s2, int l1, int l2) {
    if (l1 == 0 || l2 == 0)
        return 0;
    if (s1[l1-1] == s2[l2-1])
        return 1 + lcs_recursive(s1, s2, l1-1, l2-1);
    else
        return max(lcs_recursive(s1, s2, l1-1, l2), lcs_recursive(s1, s2, l1, l2-1));
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs_recursive(s1, s2, s1.length(), s2.length());
    return 0;
}
