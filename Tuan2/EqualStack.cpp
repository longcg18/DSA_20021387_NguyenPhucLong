int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    stack<int> st1, st2, st3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < h1.size(); i++) {
        st1.push(h1[h1.size() - i - 1]);
        sum1 += h1[i];
    }

    for (int i = 0; i < h2.size(); i++) {
        st2.push(h2[h2.size() - i - 1]);
        sum2 += h2[i];
    }

    for (int i = 0; i < h3.size(); i++) {
        st3.push(h3[h3.size() - i - 1]);
        sum3 += h3[i];
    }
    while (!st1.empty() && !st2.empty() && !st3.empty()){
        int MIN = min(sum1, min(sum2, sum3));
        if(MIN < sum1)
        {
            sum1 = sum1 - st1.top();
            st1.pop();
        }
        if(MIN < sum2)
        {
            sum2 = sum2 - st2.top();
            st2.pop();
        }
        if(MIN < sum3)
        {
            sum3 = sum3 - st3.top();
            st3.pop();
        }
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
    }
    return 0;
}
