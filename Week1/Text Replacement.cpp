#include <bits/stdc++.h>
using namespace std;

int numOfWords = 0;
vector <string> text;

void input() {
    string tmp;

    while (getline(cin, tmp)) {
        text.push_back(tmp);
    }
}

void countWords(string &str) {
    istringstream iss(str);
    string word;

    while (iss >> word) {
        numOfWords++;
    }
}

int main() {
    input();

    for (int i = 0; i < text.size(); i++) {
        countWords(text[i]);
    }

    cout << numOfWords;
}
