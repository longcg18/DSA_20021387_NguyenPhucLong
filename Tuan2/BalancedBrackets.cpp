bool isAPair(char c1, char c2) {
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '[' && c2 == ']') return true;
    if(c1 == '{' && c2 == '}') return true;
    return false;
}
string isBalanced(string s) {
    string y = "YES";
    string n = "NO";
    stack <char> st;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == '[' || ch == '(' || ch == '{') st.push(ch);
        else
            if(st.empty()) return n;
        else
            if(isAPair(st.top(), ch)) st.pop();
        else return n;
    }
    if(st.empty())
        return y;
        return n;
}
