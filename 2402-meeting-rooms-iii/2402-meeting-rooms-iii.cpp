class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<int> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        
        sort(meetings.begin(), meetings.end());

        for (auto &&meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // 시간지난 회의실 비우기
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            // 만약 사용가능한 곳이 있다면
            if (!available.empty()) {
                int top = available.top();
                ans[top]++;
                available.pop();
                busy.push({end, top});
            // 없다면, 다음 빠지는곳에 미리 예약걸어놓기
            } else {
                auto top = busy.top();
                int end1 = top.first, index = top.second;

                ans[index]++;
                busy.pop();
                busy.push({top.first + end - start, index});
            }
        }

        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};