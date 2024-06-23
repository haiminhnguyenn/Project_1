#include <bits/stdc++.h>
using namespace std;

int main() {
    queue <int> q;

    while (true) {
        string str;
        cin >> str;

        if (str == "#") return 0;
        if (str == "PUSH") {
            int v;
            cin >> v;
            q.push(v);
        }

        if (str == "POP") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            }
            else cout << "NULL" << endl;
        }
    }
}

