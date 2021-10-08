#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    cout << "Nhap so luong nguoi: ";
    int n;
    cin >> n;

    map <string, string> m;
    cout << "Nhap ten va so dien thoai theo cu phap: ten<daucach>sodienthoai:" << endl;
    for(int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        m[s1] = s2;
    }
    string q;
    map <string, string> ::iterator it;
    cout << "Tim kiem so dien thoai theo ten:" << endl;
    while(cin >> q)
    {
        it = m.find(q);
        if(it != m.end())
            cout << q << " = " << it->second <<endl;
        else
            cout << "Not found." << endl;
    }
    return 0;
}
