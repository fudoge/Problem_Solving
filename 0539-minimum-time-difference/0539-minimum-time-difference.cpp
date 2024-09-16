class Solution {
public:
    int timeToMins(string time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(const auto &time : timePoints) {
            minutes.push_back(timeToMins(time));
        }
        sort(minutes.begin(), minutes.end());

        int minDiff = 1440 + minutes[0] - minutes.back();
        for(int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }

        return minDiff;
    }
};