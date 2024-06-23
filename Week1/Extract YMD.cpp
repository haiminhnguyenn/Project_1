#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    if (str.size() != 10) cout << "INCORRECT";
    else {
        if (str[4] != '-' || str[7] != '-') cout << "INCORRECT";
        else {
            str[4] = '0'; str[7] = '0';
            for (int i = 0; i < 10; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    cout << "INCORRECT";
                    return 0;
                }
            }

            if (str[5] > '1' || str[8] > '3') cout << "INCORRECT";
            else if ((str[5] == '1' && str[6] > '2') || (str[8] == '3' && str[9] > '1')) cout << "INCORRECT";
            else {
                str[4] = ' '; str[7] = ' ';
                for (int i = 0; i < 10; i++) {
                    if ((i == 5 || i == 8) && str[i] == '0') continue;
                    cout << str[i];
                }
            }
        }
    }
}
