#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<string> database;
    string key;

    while (true) {
        cin >> key;
        if (key == "*") {
            break;
        }
        database.insert(key);
    }

    while (true) {
        string command, k;
        cin >> command;
        if (command == "***") {
            break;
        }
        cin >> k;

        if (command == "find") {
            if (database.find(k) != database.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (command == "insert") {
            if (database.insert(k).second) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}
