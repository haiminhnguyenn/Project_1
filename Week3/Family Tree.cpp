#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> familyTree;
map<string, int> generation;

int countDescendants(string name) {
    if (familyTree.find(name) == familyTree.end()) {
        return 0;
    }

    int descendants = 0;
    for (string child : familyTree[name]) {
        descendants += 1 + countDescendants(child);
    }

    return descendants;
}

int countGenerations(string name) {
    if (generation.find(name) != generation.end()) {
        return generation[name];
    }

    if (familyTree.find(name) == familyTree.end()) {
        return 0;
    }

    int maxGeneration = 0;
    for (string child : familyTree[name]) {
        maxGeneration = max(maxGeneration, 1 + countGenerations(child));
    }

    generation[name] = maxGeneration;
    return maxGeneration;
}

int main() {
    string line;
    while (getline(cin, line) && line != "***") {
        string child, parent;
        istringstream iss(line);
        iss >> child >> parent;
        familyTree[parent].push_back(child);
    }

    while (getline(cin, line) && line != "***") {
        string cmd, param;
        istringstream iss(line);
        iss >> cmd >> param;
        if (cmd == "descendants") {
            int descendants = countDescendants(param);
            cout << descendants << endl;
        } else if (cmd == "generation") {
            int generations = countGenerations(param);
            cout << generations << endl;
        }
    }

    return 0;
}
