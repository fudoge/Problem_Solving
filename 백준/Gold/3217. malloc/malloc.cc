#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct result {
    int size;
    string var;
    string cmd;

    result(int size, string& var, string& cmd) {
        this->size = size;
        this->var = var;
        this->cmd = cmd;
    }
};

result parse(string& s) {
    string var = "";
    string cmd = "";
    if (s[4] == '=') {
        int i = 12;
        cmd = "malloc";
        var = s.substr(0, 4);
        string sz = "";
        while (i < s.size() && s[i] != ')') {
            sz += s[i++];
        }
        int size = stoi(sz);

        return result(size, var, cmd);
    } else if (s[5] == '(') {
        var = s.substr(6, 4);
        cmd = "print";

        return result(0, var, cmd);
    } else if (s[4] == '(') {
        var = s.substr(5, 4);
        cmd = "free";

        return result(0, var, cmd);
    }

    return result(-1, var, cmd);
}

int allocate(int sz, set<pii>& freeBlocks) {
    for (auto it = freeBlocks.begin(); it != freeBlocks.end(); it++) {
        int l = it->first, r = it->second;
        int len = r - l + 1;
        if (len >= sz) {
            int addr = l;
            int newL = l + sz;
            freeBlocks.erase(it);
            if (newL <= r) freeBlocks.insert({newL, r});
            return addr;
        }
    }

    return 0;
}

void deallocate(int addr, int sz, set<pii>& freeBlocks) {
    int l = addr, r = addr + sz - 1;
    auto it = freeBlocks.lower_bound({l, r});
    // merge left
    if (it != freeBlocks.begin()) {
        auto prev = it;
        --prev;
        if (prev->second + 1 >= l) {
            l = prev->first;
            r = max(r, prev->second);
            freeBlocks.erase(prev);
        }
    }

    // merge right
    while (it != freeBlocks.end() && it->first <= r + 1) {
        l = min(l, it->first);
        r = max(r, it->second);
        auto nxt = next(it);
        freeBlocks.erase(it);
        it = nxt;
    }
    freeBlocks.insert({l, r});
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string, pii> varVals;
    set<pii> freeBlocks;
    freeBlocks.insert({1, 100000});

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        auto res = parse(s);
        if (res.cmd == "malloc") {
            int addr = allocate(res.size, freeBlocks);
            varVals[res.var] = {addr, (addr == 0 ? 0 : res.size)};
        } else if (res.cmd == "print") {
            cout << varVals[res.var].first << "\n";
        } else if (res.cmd == "free") {
            auto [addr, sz] = varVals[res.var];
            if (addr != 0) {
                deallocate(addr, sz, freeBlocks);
                varVals[res.var] = {0, 0};
            }
        }
    }

    return 0;
}
