#include <bits/stdc++.h>
using namespace std;

int toInt(string s) {
    int result = 0, multiplier = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        result += (s[i] - '0') * multiplier;
        multiplier *= 10;
    }
    return result;
}

int main() {
    vector<int> maxAncestorAge(100005, 0);
    vector<int> relationCount(100005, 0);
    vector<vector<vector<int>>> birthStats(200, vector<vector<int>>(12, vector<int>(31, 0)));
    int birthIndex[150000];
    int totalPeople = 0, numForMR = 0;
    string currentID, birthDate, fatherID, motherID, isAlive, relationCode;

    cin >> currentID;
    while (currentID != "*") {
        totalPeople += 1;
        cin >> birthDate >> fatherID >> motherID >> isAlive >> relationCode;

        if (fatherID != "0000000") {
            maxAncestorAge[toInt(currentID)] = max(maxAncestorAge[toInt(fatherID)], maxAncestorAge[toInt(motherID)]) + 1;
            relationCount[toInt(currentID)] += 2;
            relationCount[toInt(fatherID)] += 1;
            relationCount[toInt(motherID)] += 1;
            numForMR += 2;
        }

        birthStats[(birthDate[0] - '0') * 1000 + (birthDate[1] - '0') * 100 + (birthDate[2] - '0') * 10 + birthDate[3] - '0' - 1900]
                  [(birthDate[5] - '0') * 10 + birthDate[6] - '0' - 1]
                  [(birthDate[8] - '0') * 10 + birthDate[9] - '0' - 1] += 1;

        birthIndex[((birthDate[0] - '0') * 1000 + (birthDate[1] - '0') * 100 + (birthDate[2] - '0') * 10 + birthDate[3] - '0' - 1900) * 500
                   + ((birthDate[5] - '0') * 10 + birthDate[6] - '0') * 33
                   + (birthDate[8] - '0') * 10 + birthDate[9] - '0'] += 1;

        cin >> currentID;
    }

    for (int i = 1; i < 150000; i++) {
        birthIndex[i] += birthIndex[i - 1];
    }

    cin >> currentID;
    while (currentID != "***") {
        if (currentID == "NUMBER_PEOPLE_BORN_BETWEEN") {
            cin >> currentID >> birthDate;
            cout << birthIndex[((birthDate[0] - '0') * 1000 + (birthDate[1] - '0') * 100 + (birthDate[2] - '0') * 10 + birthDate[3] - '0' - 1900) * 500
                              + ((birthDate[5] - '0') * 10 + birthDate[6] - '0') * 33
                              + (birthDate[8] - '0') * 10 + birthDate[9] - '0']
                 - birthIndex[((currentID[0] - '0') * 1000 + (currentID[1] - '0') * 100 + (currentID[2] - '0') * 10 + currentID[3] - '0' - 1900) * 500
                                  + ((currentID[5] - '0') * 10 + currentID[6] - '0') * 33
                                  + (currentID[8] - '0') * 10 + currentID[9] - '0' - 1] << "\n";
            cin >> currentID;
        } else if (currentID == "MOST_ALIVE_ANCESTOR") {
            cin >> currentID;
            cout << maxAncestorAge[toInt(currentID)] << "\n";
            cin >> currentID;
        } else if (currentID == "NUMBER_PEOPLE_BORN_AT") {
            cin >> birthDate;
            cout << birthStats[(birthDate[0] - '0') * 1000 + (birthDate[1] - '0') * 100 + (birthDate[2] - '0') * 10 + birthDate[3] - '0' - 1900]
                              [(birthDate[5] - '0') * 10 + birthDate[6] - '0' - 1]
                              [(birthDate[8] - '0') * 10 + birthDate[9] - '0' - 1] << "\n";
            cin >> currentID;
        } else if (currentID == "NUMBER_PEOPLE") {
            cout << totalPeople << "\n";
            cin >> currentID;
        } else {
            sort(relationCount.begin(), relationCount.end(), [](int a, int b) {
                return a > b;
            });

            int idx = 0;
            while (numForMR > 0) {
                numForMR -= relationCount[idx];
                idx++;
            }
            cout << totalPeople - idx << "\n";
            cin >> currentID;
        }
    }

    return 0;
}
