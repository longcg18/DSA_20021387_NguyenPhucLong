#include <iostream>
#include <stack>

using namespace std;
int main ()
{
    int n;
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        stk.push(temp);
    }
    // stack stk has n numbers
    /**Use a temporary stack to sort a stack */
    stack<int> tempStack;
    while (!stk.empty()) {
        int tmp = stk.top();
        stk.pop();
        while(!tempStack.empty() && tempStack.top() > tmp) {
            stk.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(tmp);
    }

    /// check output
    while(!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    //end
    return 0;
}
