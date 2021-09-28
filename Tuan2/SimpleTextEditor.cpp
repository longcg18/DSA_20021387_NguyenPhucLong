#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
/**
1 str : add t at end
2 k : delete k letter from end
3 k : print kth letter
4   : undo the last update
*/
int main() {
    int Q;
    cin >> Q;
    stack <string> st;
    string s;
    while (Q--)
    {
        int n;
        cin >> n;
        if(n == 1) {
            string str;
            cin >> str;
            st.push(s);
            s = s + str;
        }
        else if(n == 2) {
            int k;
            cin >> k;
            st.push(s);
            s.erase(s.size() - k);
        }
        else if(n == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        }
        else {
            s = st.top();
            st.pop();
        }
    }
    return 0;
}
