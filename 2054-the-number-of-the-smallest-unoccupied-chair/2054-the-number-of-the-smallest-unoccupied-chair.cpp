#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

struct comp{
    bool operator()(const auto &a, const auto &b) {
        return a[1] > b[1];
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<vector<int>, vector<vector<int>>, comp> outGoing; //{chariNo., end}
        priority_queue<int, vector<int>, greater<int>> nextSeats; // {charirNo.}

        int targetTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        int maxChairNo = 0;
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            int starts = times[i][0];
            int ends = times[i][1];
            while(!outGoing.empty() && starts >= outGoing.top()[1]) {
                nextSeats.push(outGoing.top()[0]);
                outGoing.pop();
            }

            int seat;
            if(!nextSeats.empty()) {
                seat = nextSeats.top();
                nextSeats.pop();
            } else {
                seat = maxChairNo++;
            }
            if(starts == targetTime) {
                ans = seat;
                break;
            }
            outGoing.push({seat, ends});
        }
        return ans;
    }
};