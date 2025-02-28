#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int get_pure_layer(int id) { return id & 0x1FFF; }
int get_pure_id(int id) { return id >> 17; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, vector<pii>> mp;
    unordered_map<int, int> layerCounts;
    int layer = 0;
    string exp;

    while (cin >> exp) {
        if (exp == "{") {
            layer++;
            layerCounts[layer]++;
            continue;
        } else if (exp == "}") {
            layer--;
            continue;
        }

        int mid = 0;
        while (exp[mid] != '=') {
            mid++;
        }

        string lvalue = exp.substr(0, mid);
        string rvalue = exp.substr(mid + 1);
        if (lvalue == rvalue) {
            while (
                !mp[lvalue].empty() &&
                (get_pure_layer(mp[lvalue].back().second) > layer ||
                 get_pure_id(mp[lvalue].back().second) <
                     layerCounts[get_pure_layer(mp[rvalue].back().second)])) {
                mp[lvalue].pop_back();
            }

            if (mp[lvalue].empty()) mp[lvalue].push_back({0, layer});
            cout << mp[lvalue].back().first << "\n";
            continue;
        }

        while (!mp[lvalue].empty() &&
               get_pure_layer(mp[lvalue].back().second) >= layer) {
            mp[lvalue].pop_back();
        }

        if ((rvalue[0] >= '0' && rvalue[0] <= '9') || rvalue[0] == '-') {
            int val = stoi(rvalue);
            mp[lvalue].push_back({val, layer | (layerCounts[layer] << 17)});
        } else {
            while (
                !mp[rvalue].empty() &&
                (get_pure_layer(mp[rvalue].back().second) > layer ||
                 get_pure_id(mp[rvalue].back().second) <
                     layerCounts[get_pure_layer(mp[rvalue].back().second)])) {
                mp[rvalue].pop_back();
            }
            if (mp[rvalue].empty()) {
                mp[lvalue].push_back({0, layer | layerCounts[layer] << 17});
            } else {
                mp[lvalue].push_back({mp[rvalue].back().first,
                                      layer | (layerCounts[layer] << 17)});
            }
            cout << mp[lvalue].back().first << "\n";
        }
    }

    return 0;
}