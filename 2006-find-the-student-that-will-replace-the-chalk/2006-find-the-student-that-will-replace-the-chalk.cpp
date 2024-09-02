class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(const auto &x : chalk) {
            total += x;
        }
        k %= total;

        for(int i = 0; i < chalk.size(); i++) {
            if(chalk[i] <= k) k -= chalk[i];
            else return i;
        }

        return 0;
    }
};