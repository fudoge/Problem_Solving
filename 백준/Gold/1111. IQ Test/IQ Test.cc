#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1) {
        cout << "A\n";
        return 0;
    }

    if (n == 2) {
        if (arr[0] == arr[1]) {
            cout << arr[1] << "\n";
        } else {
            cout << "A\n";
        }
        return 0;
    }

    for (int a = -200; a <= 200; a++) {
        int b = arr[1] - arr[0] * a;
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] * a + b != arr[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << arr.back() * a + b << "\n";
            return 0;
        }
    }

    cout << "B\n";
    return 0;
}