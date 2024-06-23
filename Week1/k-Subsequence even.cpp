#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0, weightFromIndex[n];
    memset(weightFromIndex, 0, sizeof(weightFromIndex));

    // Tính tổng cho cửa sổ đầu tiên
    for (int i = 0; i < k; i++) {
        weightFromIndex[0] += a[i];
    }

    // Sử dụng phương pháp trượt cửa sổ để tính toán tổng cho các cửa sổ tiếp theo
    for (int i = 1; i <= n - k; i++) {
        weightFromIndex[i] = weightFromIndex[i - 1] - a[i - 1] + a[i + k - 1];
    }

    for (int i = 0; i < n; i++) {
        if (weightFromIndex[i] % 2 == 0 && weightFromIndex[i] > 0) count++;
    }

    cout << count;
}
