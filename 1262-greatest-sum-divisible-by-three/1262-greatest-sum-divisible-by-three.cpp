class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int mod1_min = 1e9;
        int mod1_min2 = 1e9;
        int mod2_min = 1e9;
        int mod2_min2 = 1e9;

        int sum = 0;
        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) {
                if (num <= mod1_min) {
                    mod1_min2 = mod1_min;
                    mod1_min = num;
                } else if (num <= mod1_min2) {
                    mod1_min2 = num;
                }
            } else if (num % 3 == 2) {
                if (num <= mod2_min) {
                    mod2_min2 = mod2_min;
                    mod2_min = num;
                } else if (num <= mod2_min2) {
                    mod2_min2 = num;
                }
            }
        }

        if (sum % 3 == 1) {
            sum = max(sum - mod2_min - mod2_min2, sum - mod1_min);
        } else if (sum % 3 == 2) {
            sum = max(sum - mod1_min - mod1_min2, sum - mod2_min);
        }

        return sum;
    }
};