#include <bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int d, n, s, p;
        cin >> d >> n >> s >> p;

        long long serialized = n * s;
        long long parallel = d + (n * p);

        if (serialized == parallel) {
            cout << "does not matter\n";
        } else if (serialized > parallel) {
            cout << "parallelize\n";
        } else {
            cout << "do not parallelize\n";
        }
    }

    return 0;
}