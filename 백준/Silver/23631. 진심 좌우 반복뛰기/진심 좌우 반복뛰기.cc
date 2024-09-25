#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    int t;
    cin >> t;

    vector<pair<int, char>> ans;
    int n, k;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        n--;
        if (n < k) {
          ans.push_back({n, 'R'});
          continue;
        }

        int m = int(-1 + sqrt(1 + (8 * (float)n / (float)k))) / 2;
        int len =  k * (m * (m+1) / 2);

        int leftLen = n - len;
        int pos = ((m-1)/2+1) * k * (m % 2 == 1? 1 : -1);
        if(m % 2 == 1) {
          ans.push_back({pos - leftLen, 'L'});
        } else {
          ans.push_back({pos + leftLen , 'R'});
        }
    }

    for (const auto &c : ans) {
        cout << c.first << " " << c.second << "\n";
    }

    return 0;
}