#include <bits/stdc++.h>
using namespace std;

void generatePermutations(int n, vector<int>& permutation, vector<bool>& used) {
    if (permutation.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            permutation.push_back(i);
            generatePermutations(n, permutation, used);
            permutation.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> permutation;
    vector<bool> used(n + 1, false);

    generatePermutations(n, permutation, used);

    return 0;
}

