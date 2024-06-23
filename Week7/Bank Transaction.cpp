#include <bits/stdc++.h>
using namespace std;

int transactionCount;
string startingAccount;
long long totalTransactionAmount = 0;
int cycleLength = 0;
bool cycleFound;
map<string, vector<string>> transactionMap;
map<string, int> transactionAmountFromAccount;
vector<string> accountNames, savedPath;

bool hasDuplicate() {
    for (int i = 0; i < savedPath.size(); ++i) {
        for (int j = i + 1; j < savedPath.size(); ++j) {
            if (savedPath[i] == savedPath[j]) {
                return true;
            }
        }
    }
    return false;
}

void handleCycle() {
    if (!hasDuplicate() && cycleFound && savedPath[savedPath.size() - 1] == startingAccount) {
        cout << 1 << endl;
        cycleFound = false;
    }
}

void explorePaths(string currentAccount, int steps) {
    for (int i = 0; i < transactionMap[currentAccount].size(); i++) {
        savedPath.push_back(transactionMap[currentAccount][i]);
        if (steps == cycleLength) {
            handleCycle();
        } else {
            explorePaths(transactionMap[currentAccount][i], steps + 1);
        }
        savedPath.pop_back();
    }
}

int main() {
    string transactionType;

    do {
        cin >> transactionType;
        if (transactionType == "#") continue;
        else {
            string account, bank, time;
            int amount;
            cin >> account >> amount >> time >> bank;
            transactionCount++;
            totalTransactionAmount += amount;
            transactionAmountFromAccount[transactionType] += amount;
            transactionMap[transactionType].push_back(account);
            accountNames.push_back(transactionType);
            accountNames.push_back(account);
        }
    } while (transactionType != "#");

    do {
        cin >> transactionType;
        if (transactionType == "#") continue;
        if (transactionType == "?number_transactions") cout << transactionCount << endl;
        if (transactionType == "?total_money_transaction") cout << totalTransactionAmount << endl;
        if (transactionType == "?list_sorted_accounts") {
            sort(accountNames.begin(), accountNames.end());
            for (int i = 0; i < accountNames.size(); i++)
                if (accountNames[i] != accountNames[i + 1]) cout << accountNames[i] << " ";
            cout << endl;
        }
        if (transactionType == "?total_money_transaction_from") {
            string account;
            cin >> account;
            cout << transactionAmountFromAccount[account] << endl;
        }
        if (transactionType == "?inspect_cycle") {
            cin >> startingAccount;
            cin >> cycleLength;
            cycleFound = true;
            explorePaths(startingAccount, 1);
            if (cycleFound == true) cout << 0 << endl;
        }
    } while (transactionType != "#");
}
