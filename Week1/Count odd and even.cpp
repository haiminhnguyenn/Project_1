#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, countOdd = 0, countEven = 0;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 != 0) countOdd++;
        else countEven++;
    }

    cout << countOdd << " " << countEven;
}
