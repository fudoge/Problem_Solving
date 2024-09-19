class Solution {
private:
    vector<int> dp[20][20];
    vector<int> convert(string &expression) {
        vector<int> res;
        int x = 0;
        int size = expression.size();
        for(int i = 0; i < size; i++) {
            char c = expression[i];
            switch(c) {
                case '+': res.push_back(101); break;
                case '-': res.push_back(102); break;
                case '*': res.push_back(103); break;
                default: {
                    x = 10 * x + c - '0';
                    if (i == size-1 || !isdigit(expression[i+1])) {
                        res.push_back(x);
                        x = 0;
                    }
                }
            }
        }

        return res;
    }

    vector<int> solve(int left, int right, vector<int> &nums) {
        if(left > right) return {};
        if(left == right){ 
            if(nums[left] >= 101) return {};
            return {nums[left]};
        }
        if(dp[left][right].size() > 0) return dp[left][right];

        vector<int> res;
        for(int i = left; i <= right; i++) {
            if(nums[i] < 100) continue;
            auto operandL = solve(left, i-1, nums);
            auto operandR = solve(i+1, right, nums);
            for(int l : operandL) {
                for(int r : operandR) {
                    int x = 0;
                    switch(nums[i]) {
                        case 101: res.push_back(l + r); break;
                        case 102: res.push_back(l - r); break;
                        case 103: res.push_back(l * r); break;
                    }
                }
            }
        }
        return dp[left][right] = res;
        
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums = convert(expression);
        int n = nums.size();
        return solve(0, n-1, nums);
    }
};