using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int a : answers) {
            freq[a]++;
        }

        for (auto& [x, count] : freq) {
            int group_size = x + 1;
            int groups = (count + x) / group_size;
            res += groups * group_size;
        }

        return res;
    }
};