#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int maxGroupNo = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{endtime, groupNo}
        priority_queue<int, vector<int>, greater<int>> next;
        for(const auto &member : intervals) {
            int left = member[0];
            int right = member[1];

            while(!pq.empty() && left > pq.top().first) {
                next.push(pq.top().second);
                pq.pop();
            }

            int groupNo;
            if(!next.empty()) {
                groupNo = next.top();
                next.pop();
            } else {
                groupNo = maxGroupNo++;
            }

            pq.push({right, groupNo});
        }

        return maxGroupNo-1;
    }
};