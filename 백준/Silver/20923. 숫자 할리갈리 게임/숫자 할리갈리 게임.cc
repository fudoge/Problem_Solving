#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> d, s;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d.emplace_back(a);
        s.emplace_back(b);
    }

    deque<int> ground_do, ground_su;
    for (int i = 0; i < m; i++) {
        bool do_turn = (i & 1) == 0;
        if (do_turn) {
            if (d.empty()) {
                cout << "su\n";
                return 0;
            }
            ground_do.emplace_back(d.back());
            d.pop_back();
            if (d.empty()) {
                cout << "su\n";
                return 0;
            }
        } else {
            if (s.empty()) {
                cout << "do\n";
                return 0;
            }
            ground_su.emplace_back(s.back());
            s.pop_back();
            if (s.empty()) {
                cout << "do\n";
                return 0;
            }
        }
        if ((!ground_do.empty() && ground_do.back() == 5) ||
            (!ground_su.empty() && ground_su.back() == 5)) {
            while (!ground_su.empty()) {
                d.push_front(ground_su.front());
                ground_su.pop_front();
            }
            while (!ground_do.empty()) {
                d.push_front(ground_do.front());
                ground_do.pop_front();
            }
        }
        if (!ground_do.empty() && !ground_su.empty() &&
            ground_do.back() + ground_su.back() == 5) {
            while (!ground_do.empty()) {
                s.push_front(ground_do.front());
                ground_do.pop_front();
            }
            while (!ground_su.empty()) {
                s.push_front(ground_su.front());
                ground_su.pop_front();
            }
        }
        if (d.empty()) {
            cout << "su\n";
            return 0;
        }
        if (s.empty()) {
            cout << "do\n";
            return 0;
        }
    }

    if (d.size() == s.size()) {
        cout << "dosu\n";
    } else if (d.size() > s.size()) {
        cout << "do\n";
    } else {
        cout << "su\n";
    }

    return 0;
}