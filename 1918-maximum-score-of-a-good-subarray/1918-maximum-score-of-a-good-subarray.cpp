class Solution{
public:
    int maximumScore(vector<int> &nums, int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        const int n = nums.size();
        int left = k;
        int right = k;
        int minNum = nums[k];
        int maxScore = INT_MIN;
        while (true){
            // update maxScore..
            int score = (right - left + 1) * minNum;
            maxScore = max(maxScore, score);

            if (left > 0){
                if (right < n-1){
                    if (nums[left - 1] >= nums[right + 1]){
                        left--;
                        minNum = min(minNum, nums[left]);
                    }
                    else{
                        right++;
                        minNum = min(minNum, nums[right]);
                    }
                }
                else{
                    left--;
                    minNum = min(minNum, nums[left]);
                }
            }
            else{
                if (right < n-1){
                    right++;
                    minNum = min(minNum, nums[right]);
                }
                //end: left == 0 && right == n-1
                else break;
            }
        }

        return maxScore;
    }
};