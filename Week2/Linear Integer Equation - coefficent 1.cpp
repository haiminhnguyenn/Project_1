#include <bits/stdc++.h>
using namespace std;

void generateSets(int n, int M, vector<int>& currentSet) {
    if (n == 0) {
        if (M == 0) {
            for (int i = 0; i < currentSet.size(); i++) {
                cout << currentSet[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= M; i++) {
        currentSet.push_back(i);
        generateSets(n - 1, M - i, currentSet);
        currentSet.pop_back();
    }
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> currentSet;

    generateSets(n, M, currentSet);

    return 0;
}

