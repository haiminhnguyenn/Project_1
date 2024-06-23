#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, steps;
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minSteps(int a, int b, int target) {
    if (target % gcd(a, b) != 0) {
        return -1;
    }

    queue<State> q;
    set<pair<int, int>> visited;

    q.push({0, 0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.x == target || current.y == target) {
            return current.steps;
        }

        if (visited.find({a, current.y}) == visited.end()) {
            q.push({a, current.y, current.steps + 1});
            visited.insert({a, current.y});
        }

        if (visited.find({current.x, b}) == visited.end()) {
            q.push({current.x, b, current.steps + 1});
            visited.insert({current.x, b});
        }

        int pour = min(current.x, b - current.y);
        if (visited.find({current.x - pour, current.y + pour}) == visited.end()) {
            q.push({current.x - pour, current.y + pour, current.steps + 1});
            visited.insert({current.x - pour, current.y + pour});
        }

        pour = min(a - current.x, current.y);
        if (visited.find({current.x + pour, current.y - pour}) == visited.end()) {
            q.push({current.x + pour, current.y - pour, current.steps + 1});
            visited.insert({current.x + pour, current.y - pour});
        }

        if (visited.find({0, current.y}) == visited.end()) {
            q.push({0, current.y, current.steps + 1});
            visited.insert({0, current.y});
        }


        if (visited.find({current.x, 0}) == visited.end()) {
            q.push({current.x, 0, current.steps + 1});
            visited.insert({current.x, 0});
        }
    }

    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int steps = minSteps(a, b, c);
    cout << steps << endl;

    return 0;
}
