#include <bits/stdc++.h>

using namespace std;

string trim(const string &s) {
    auto start = s.find_first_not_of(" \t\n\r");
    auto end = s.find_last_not_of(" \t\n\r");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string str;
        getline(cin, str);
        str = trim(str);
        if (str.empty()) {
            cout << "invalid input\n";
            continue;
        }
        bool is_number = all_of(str.begin(), str.end(), ::isdigit);

        if (is_number) {
            int k = 0;
            while (str[k] == '0') k++;
            cout << (str.substr(k).empty() ? "0" : str.substr(k)) << "\n";
        } else {
            cout << "invalid input\n";
        }
    }

    return 0;
}