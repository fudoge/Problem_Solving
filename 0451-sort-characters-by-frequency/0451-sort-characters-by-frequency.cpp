struct comp {
    bool operator()(const auto &a, const auto &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        unordered_map<char, int> mp;

        for(const char &ch : s) {
            mp[ch]++;
        }

        for(const auto &entry : mp) {
            pq.push({entry.first, entry.second});
        }

        string res = "";
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            res.append(p.second, p.first);
        }

        return res;
    }
};