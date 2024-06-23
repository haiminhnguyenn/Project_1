#include <bits/stdc++.h>
using namespace std;

void generateBinaryStrings(int n) {
    for (int i = 0; i < (1 << n); ++i) {
        string binary = bitset<20>(i).to_string().substr(20 - n);
        cout << binary << endl;
    }
}

int main() {
    int n;
    cin >> n;

    generateBinaryStrings(n);

    return 0;
}

