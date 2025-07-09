#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int init;
    cin >> init;

    int price[15];
    for (int i = 1; i <= 14; i++) {
        cin >> price[i];
    }
    price[0] = price[1];

    int b_cash = init, t_cash = init;
    int b_stock = 0, t_stock = 0;

    int upstreak = 0;
    int downstreak = 0;

    for (int i = 1; i <= 14; i++) {
        int last = price[i - 1];
        int curr = price[i];
        if (curr > last) {
            upstreak++;
            downstreak = 0;
        } else if (curr < last) {
            downstreak++;
            upstreak = 0;
        } else {
            upstreak = 0;
            downstreak = 0;
        }

        if (b_cash >= curr) {
            int count = b_cash / curr;
            b_cash -= curr * count;
            b_stock += count;
        }
        if (upstreak >= 3) {
            t_cash += curr * t_stock;
            t_stock = 0;
        } else if (downstreak >= 3) {
            int count = t_cash / curr;
            t_cash -= curr * count;
            t_stock += count;
        }
    }

    int b_tot = b_cash + b_stock * price[14];
    int t_tot = t_cash + t_stock * price[14];

    if (b_tot > t_tot) {
        cout << "BNP";
    } else if (b_tot < t_tot) {
        cout << "TIMING";
    } else {
        cout << "SAMESAME";
    }
    cout << "\n";

    return 0;
}