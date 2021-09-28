#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void printQ(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
int main () {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    //q has n numbers
    stack<int> s;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        while(!s.empty() && s.top() > tmp) {
            q.push(s.top());
            s.pop();
        }
        s.push(tmp);
    }
    ///print
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // Queue q has been sorted
    printQ(q);
    return 0;
}
