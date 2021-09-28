#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> f, r;
    int Q;
    cin >> Q;
    while (Q--) {
        int q;
        cin >> q;
        if(q == 1) {
            int x;
            cin >> x;
            r.push(x);
        }
        else {
            if(f.empty()) {
                while(!r.empty()) {
                    f.push(r.top());
                    r.pop();
                }
            }
            if(!f.empty()) {
                if(q == 2) {
                    f.pop();
                }
                else if(q == 3) {
                    cout << f.top() << endl;
                }
            }
        }
    }
    return 0;
}
