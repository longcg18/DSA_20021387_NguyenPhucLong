#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void lcs(string s1, string s2, int l1, int l2) {
    // tim va luu lai cac xau con chung
    int com[l1][l2];

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s1[i] == s2[j]) {
                com[i][j] = 1;
            } else com[i][j] = 0;
        }
    }
    string temp = "";
    vector<string> output;

    for (int i = 0; i < l1-1; i++) {
        for (int j = 0; j < l2-1; j++) {
            if (com[i][j] == 1) {
                temp = temp + s1[i];
                if (com[i+1][j+1] == 0) {
                    output.push_back(temp);
                    temp = "";
                }
            }
        }
    }

    // Xu ly cac xau con chung

    int maxlength = output[0].length();
    int maxlengthindex = 0;

    for (int i = 0; i < output.size(); i++)
        if (maxlength < output[0].length()) {
            maxlength = output[i].length();
            maxlengthindex = i;
        }

    cout << output[maxlengthindex];
}

int main () {

    string s1, s2;
    cin >> s1 >> s2;

    //cout <<
    lcs(s1, s2, s1.length(), s2.length());
    return 0;
}
