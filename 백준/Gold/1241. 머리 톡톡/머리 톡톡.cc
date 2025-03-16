#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> num_count;
    for (int &i : a) {
        cin >> i;
        num_count[i]++;
    }

    vector<int> number_of_divisors(1000001, 0);
    for (const auto &[k, v] : num_count) {
        number_of_divisors[k] += v - 1;
        for (int i = k * 2; i <= 1000000; i += k) {
            number_of_divisors[i] += v;
        }
    }

    for (const auto &num : a) {
        cout << number_of_divisors[num] << "\n";
    }

    return 0;
}