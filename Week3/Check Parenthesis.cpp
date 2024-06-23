#include <bits/stdc++.h>
using namespace std;

int main() {
    stack <char> st;
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') st.push(str[i]);
        else st.pop();
    }

    if (st.empty()) cout << "1";
    else cout << "0";
}
