#include <bits/stdc++.h>

using namespace std;

int n; // userid_size
int m; // bannedid_size
int ans = 0;
vector<bool> mapped;
set<set<string>> unique_mappings;

bool isMatch(const string &usr, const string &ban) {
    if (usr.length() != ban.length()) return false;
    for (int i = 0; i < usr.length(); i++) {
        if (usr[i] != ban[i] && ban[i] != '*') return false;
    }
    return true;
}

void solve(vector<string> &user_id, vector<string> &banned_id, int bidIDX, set<string> current_mapping) {
    if (bidIDX >= m) {
        if (unique_mappings.find(current_mapping) == unique_mappings.end()) {
            unique_mappings.insert(current_mapping);
            ans++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mapped[i]) continue;
        if (isMatch(user_id[i], banned_id[bidIDX])) {
            mapped[i] = true;
            current_mapping.insert(user_id[i]);
            solve(user_id, banned_id, bidIDX + 1, current_mapping);
            current_mapping.erase(user_id[i]);
            mapped[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    n = user_id.size();
    m = banned_id.size();
    ans = 0;
    mapped.assign(n, false);
    unique_mappings.clear();
    
    solve(user_id, banned_id, 0, set<string>());
    
    return ans;
}