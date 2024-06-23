#include <bits/stdc++.h>
using namespace std;

int main() {
    stack <int> st;

    while (true) {
        string str;
        cin >> str;

        if (str == "#") return 0;
        if (str == "PUSH") {
            int v;
            cin >> v;
            st.push(v);
        }

        if (str == "POP") {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else cout << "NULL" << endl;
        }
    }
}
