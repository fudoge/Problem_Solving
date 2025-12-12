#pragma GCC optimize("O3", "unroll-loops");
static const int __ [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            int aTime = stoi(a[1]);
            int bTime = stoi(b[1]);
            if(aTime == bTime) {
                return a[0] == "OFFLINE";
            }
            return aTime < bTime;
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // ts, id
        vector<int> ans(numberOfUsers, 0);
        vector<bool> alive(numberOfUsers, true);

        for(int i = 0; i < n;) {
            int ts = stoi(events[i][1]);
            while(!minHeap.empty() && minHeap.top().first <= ts) {
                alive[minHeap.top().second] = true;
                minHeap.pop();
            }
            int j = i;
            while(j < n && ts == stoi(events[j][1])) {
                if(events[j][0] == "OFFLINE") {
                    int uid = stoi(events[j][2]);
                    minHeap.emplace(ts+60, uid);
                    alive[uid] = false;
                } else {
                    if(events[j][2] == "ALL") {
                        for(int k = 0; k < numberOfUsers; k++) {
                            ans[k]++;
                        }
                    } else if(events[j][2] == "HERE") {
                        for(int k = 0; k < numberOfUsers; k++) {
                            if(alive[k]) ans[k]++;
                        }
                    } else {
                        stringstream ss(events[j][2]);
                        string tok;
                        while(ss >> tok) {
                            int uid = stoi(tok.substr(2));
                            ans[uid]++;
                        }
                    }
                }
                j++;
            }

            i = j;
        }

        return ans;
    }
};