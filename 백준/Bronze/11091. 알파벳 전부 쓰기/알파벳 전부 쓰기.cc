#include <bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    for (int k = 0; k < n; k++) {
        string s;
        getline(cin, s);
        vector<int> freq(26, 0);
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                freq[ch - 'A']++;
            } else if (ch >= 'a' && ch <= 'z') {
                freq[ch - 'a']++;
            }
        }

        string missing;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) missing += ('a' + i);
        }

        if (missing.size() == 0) {
            cout << "pangram\n";
        } else {
            cout << "missing " << missing << "\n";
        }
    }

    return 0;
}