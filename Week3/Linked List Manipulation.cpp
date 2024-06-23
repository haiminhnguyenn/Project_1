#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> linkedList;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        linkedList.push_back(value);
    }

    string command;
    while (cin >> command) {
        if (command == "addlast") {
            int k;
            cin >> k;
            if (find(linkedList.begin(), linkedList.end(), k) == linkedList.end()) {
                linkedList.push_back(k);
            }
        } else if (command == "addfirst") {
            int k;
            cin >> k;
            if (find(linkedList.begin(), linkedList.end(), k) == linkedList.end()) {
                linkedList.push_front(k);
            }
        } else if (command == "addafter") {
            int u, v;
            cin >> u >> v;
            auto it = find(linkedList.begin(), linkedList.end(), v);
            if (it != linkedList.end()) {
                advance(it, 1);
                if (find(linkedList.begin(), linkedList.end(), u) == linkedList.end()) {
                    linkedList.insert(it, u);
                }
            }
        } else if (command == "addbefore") {
            int u, v;
            cin >> u >> v;
            auto it = find(linkedList.begin(), linkedList.end(), v);
            if (it != linkedList.end()) {
                if (find(linkedList.begin(), linkedList.end(), u) == linkedList.end()) {
                    linkedList.insert(it, u);
                }
            }
        } else if (command == "remove") {
            int k;
            cin >> k;
            linkedList.remove(k);
        } else if (command == "reverse") {
            linkedList.reverse();
        } else if (command == "#") {
            break;
        }
    }

    for (int value : linkedList) {
        cout << value << " ";
    }

    return 0;
}
