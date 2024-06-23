#include <bits/stdc++.h>
using namespace std;

int totalOrders = 0, totalRevenue = 0;
map<pair<string, string>, int> customerShopMap;
map<string, int> shopRevenueMap;

struct Transaction {
    string customerID;
    string productID;
    int price;
    string shopID;
    string timestamp;
};

Transaction transactions[100001];
int cumulativeRevenue[86401];

int convertTimestamp(string timestamp) {
    int totalSeconds = 0;
    totalSeconds = ((timestamp[0] - '0') * 10 + (timestamp[1] - '0')) * 60 * 60;
    totalSeconds += ((timestamp[3] - '0') * 10 + (timestamp[4] - '0')) * 60;
    totalSeconds += ((timestamp[6] - '0') * 10 + (timestamp[7] - '0'));
    return totalSeconds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string transactionType;

    do {
        cin >> transactionType;
        if (transactionType == "#") continue;
        else {
            totalOrders++;
            string customer, product, shop, timestamp;
            int price;
            customer = transactionType;
            cin >> product;
            cin >> price;
            cin >> shop;
            cin >> timestamp;
            totalRevenue += price;
            transactions[totalOrders].customerID = customer;
            transactions[totalOrders].price = price;
            transactions[totalOrders].productID = product;
            transactions[totalOrders].shopID = shop;
            transactions[totalOrders].timestamp = timestamp;
            cumulativeRevenue[convertTimestamp(timestamp)] += price;
            shopRevenueMap[shop] += price;
            pair<string, string> customerShopPair = make_pair(customer, shop);
            customerShopMap[customerShopPair] += price;
        }
    } while (transactionType != "#");

    for (int i = 1; i <= 86400; i++) {
        cumulativeRevenue[i] += cumulativeRevenue[i - 1];
    }

    do {
        cin >> transactionType;
        if (transactionType == "#") continue;
        if (transactionType == "?total_number_orders") cout << totalOrders << endl;
        if (transactionType == "?total_revenue") cout << totalRevenue << endl;
        if (transactionType == "?revenue_of_shop") {
            string shopName;
            int shopRevenue = 0;
            cin >> shopName;
            shopRevenue = shopRevenueMap[shopName];
            cout << shopRevenue << endl;
        }
        if (transactionType == "?total_consume_of_customer_shop") {
            string shop, customer;
            int shopRevenue = 0;
            cin >> customer;
            cin >> shop;
            pair<string, string> customerShopPair = make_pair(customer, shop);
            auto it = customerShopMap.find(customerShopPair);
            if (it != customerShopMap.end()) {
                shopRevenue = customerShopMap[customerShopPair];
                cout << shopRevenue << endl;
            } else {
                cout << 0 << endl;
            }
        }
        if (transactionType == "?total_revenue_in_period") {
            string startTime, endTime;
            int periodRevenue = 0;
            cin >> startTime;
            cin >> endTime;
            periodRevenue = cumulativeRevenue[convertTimestamp(endTime)] - cumulativeRevenue[convertTimestamp(startTime) - 1];
            cout << periodRevenue << endl;
        }
    } while (transactionType != "#");
}
