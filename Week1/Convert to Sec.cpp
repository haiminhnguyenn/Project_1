#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    if (str.size() != 8) cout << "INCORRECT";
    else {
        if (str[2] != ':' || str[5] != ':') cout << "INCORRECT";
        else {
            str[2] = '0'; str[5] = '0';
            for (int i = 0; i < 8; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    cout << "INCORRECT";
                    return 0;
                }
            }

            if (str[0] > '2' || str[3] > '5' || str[6] > '5') cout << "INCORRECT";
            else if (str[0] == '2' && str[1] > '3') cout << "INCORRECT";
            else {
                int ans;
                int hour, min, sec;
                hour = (str[0] - '0')*10 + (str[1] - '0');
                min = (str[3] - '0')*10 + (str[4] - '0');
                sec = (str[6] - '0')*10 + (str[7] - '0');
                ans = hour*3600 + min*60 + sec;
                cout << ans;
            }
        }
    }
}
