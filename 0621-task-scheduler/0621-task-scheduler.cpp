class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(auto task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int most = freq[25] - 1;
        int idle = most * n;

        for(int i = 24; i >= 0; i--) {
            idle -= min(most, freq[i]);
        }

        return idle < 0? tasks.size() : tasks.size() + idle;
    }
};