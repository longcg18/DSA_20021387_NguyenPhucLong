#include <iostream>
#include <cmath>

using namespace std;

int lcs_d(string s1, string s2, int l1, int l2) {
    int com[l1+1][l2+1];
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i == 0 || j == 0) com[i][j] = 0;
            else
            if (s1[i-1] == s2[j-1]) {
                com[i][j] = com[i-1][j-1] + 1;
            } else {
                com[i][j] = max(com[i][j-1], com[i-1][j]);
            }
        }
    }

    return com[l1][l2];
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs_d(s1, s2, s1.length(), s2.length());
    return 0;
}
