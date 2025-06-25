#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    auto cp = arr;

    bool flag = false;
    do {
        if (flag) {
            for (const auto &elem : cp) {
                cout << elem << " ";
            }
            cout << "\n";
            return 0;
        }
        bool correct = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != cp[i]) {
                correct = false;
                break;
            }
        }
        if (correct) flag = true;
    } while (next_permutation(cp.begin(), cp.end()));

    cout << "-1\n";

    return 0;
}
