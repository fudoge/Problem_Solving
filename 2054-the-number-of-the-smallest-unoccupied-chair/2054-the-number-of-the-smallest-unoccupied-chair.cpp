struct comp{
    bool operator()(const auto &a, const auto &b) {
        return a[1] > b[1];
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<vector<int>, vector<vector<int>>, comp> inComing; //{No., start, end}
        priority_queue<vector<int>, vector<vector<int>>, comp> outGoing; //{chariNo., end}
        priority_queue<int, vector<int>, greater<int>> nextSeats; // {charirNo.}

        for(int i = 0; i < n; ++i) {
            inComing.push({i, times[i][0], times[i][1]});
        }

        int maxSeatNo = 0;
        while(true) {
            int currFriend = inComing.top()[0];
            int currIn = inComing.top()[1];
            int currOut = inComing.top()[2];
            inComing.pop();

            while(!outGoing.empty() && currIn >= outGoing.top()[1]) {
                nextSeats.push(outGoing.top()[0]);
                outGoing.pop();
            }

            int seat;
            if(!nextSeats.empty()) {
                seat = nextSeats.top();
                nextSeats.pop();
            } else {
                seat = maxSeatNo++;
            }

            if(currFriend == targetFriend) return seat;
            outGoing.push({seat, currOut});
        }

        return -1;
    }
};