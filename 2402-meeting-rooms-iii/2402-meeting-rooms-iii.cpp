class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n, 0);
        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for(int i = 0; i < n; i++) {
            available.push(i);
        }

        sort(meetings.begin(), meetings.end());
        for(const auto &m : meetings) {
            int s = m[0];
            int e = m[1];

            while(!busy.empty() && busy.top().first <= s) {
                available.push(busy.top().second);
                busy.pop();
            }

            if(!available.empty()) {
                int top = available.top();
                ans[top]++;
                available.pop();
                busy.push({e, top});
            } else {
                auto top = busy.top();
                int pend = top.first;
                int room = top.second;
                ans[room]++;
                busy.pop();
                busy.push({top.first + e - s, room});
            }
        }

        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};