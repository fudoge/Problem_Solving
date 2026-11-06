class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int l = logs.size();
        int qsize = queries.size();

        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<pair<int, int>> sq;
        for(int i = 0; i < qsize; i++) {
            sq.push_back({queries[i], i});
        }
        sort(sq.begin(), sq.end());

        vector<int> cnt(n+1, 0);
        vector<int> q(qsize);
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < qsize; i++) {
            int qr = sq[i].first;

            while(right < l && logs[right][1] <= qr) {
                if(++cnt[logs[right][0]] == 1) {
                    ans++;
                }
                right++;
            }

            int ql = qr - x;
            while(left < l && logs[left][1] < ql) {
                if(--cnt[logs[left][0]] == 0) {
                    ans--;
                }
                left++;
            }

            int idx = sq[i].second;
            q[idx] = n - ans;
        }

        return q;
    }
};