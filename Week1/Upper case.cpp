#include <bits/stdc++.h>
using namespace std;

int main() {
    string text;

    while (getline(cin, text)) {
        for (int i = 0; i < text.size(); i++) {
            if (text[i] >= 'a' && text[i] <= 'z') text[i] -= 32;
        }

        cout << text << endl;
    }
}
