#include <bits/stdc++.h>
using namespace std;

double giaTheoThang6Muc(int soDien) {
    double gia;
    if (soDien <= 50) gia = 1728 * soDien * 1.1;
    if (soDien > 50 && soDien <= 100) gia = (86400 + 1786*(soDien - 50)) * 1.1;
    if (soDien > 100 && soDien <= 200) gia = (175700 + 2074*(soDien - 100)) * 1.1;
    if (soDien > 200 && soDien <= 300) gia = (383100 + 2612*(soDien - 200)) * 1.1;
    if (soDien > 300 && soDien <= 400) gia = (644300 + 2919*(soDien - 300)) * 1.1;
    if (soDien > 400) gia = (936200 + 3015*(soDien - 400)) * 1.1;
    return gia;
}

double giaTheoDeXuat(int soDien) {
    double gia;
    if (soDien <= 100) gia = 1728 * soDien * 1.1;
    if (soDien > 100 && soDien <= 200) gia = (172800 + 2074*(soDien - 100)) * 1.1;
    if (soDien > 200 && soDien <= 400) gia = (380200 + 2612*(soDien - 200)) * 1.1;
    if (soDien > 400 && soDien <= 700) gia = (902600 + 3111*(soDien - 400)) * 1.1;
    if (soDien > 700) gia = (1835900 + 3457*(soDien - 700)) * 1.1;
    return gia;
}

int main() {
    int soDien;
    cin>>soDien;

    cout << fixed << setprecision(2) << giaTheoDeXuat(soDien) - giaTheoThang6Muc(soDien);
}

