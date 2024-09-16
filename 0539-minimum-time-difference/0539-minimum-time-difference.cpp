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

        int minDiff = INT_MAX;
        for(int i = 0; i < minutes.size()-1; i++) {
            for(int j = i+1; j < minutes.size(); j++) {
                minDiff = min(minDiff, (minutes[i] - minutes[j] + 1440) % 1440);
                minDiff = min(minDiff, (minutes[j] - minutes[i] + 1440) % 1440);
            }
        }

        return minDiff;
    }
};