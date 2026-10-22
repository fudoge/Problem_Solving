class Solution {
private:
    int get_max_num_idx(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == n-1) {
                return i;
            }
        }

        return -1; 
    }
    int validate(vector<int>& nums) {
        int n = nums.size();
        int pos_dir_cnt = 0;
        int neg_dir_cnt = 0;

        for(int i = 0; i < n; i++) {
            int dir = nums[i] - nums[(i-1+n)%n];
            if(dir > 0) pos_dir_cnt++;
            else neg_dir_cnt++;
        }

        if(pos_dir_cnt == neg_dir_cnt) {
            if(pos_dir_cnt == 1 && neg_dir_cnt == 1) return 2;
            else return 0;
        }

        if(pos_dir_cnt > neg_dir_cnt) {
            if(neg_dir_cnt >= 2) return 0;
            else return 1;
        } else {
            if(pos_dir_cnt >= 2) return 0;
            else return -1;
        }
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int dir = validate(nums);
        if(dir == 0) return -1;

        if(dir == 2) {
            return nums[0];
        }

        if(dir == 1) {
            int max_num_idx = get_max_num_idx(nums);
            int cand1 = (max_num_idx + 1) % n;

            int reversed_max_num_idx = (n-1) - max_num_idx;
            int cand2 = reversed_max_num_idx + 2;
            if(cand2 >= n+1) cand2 -= n;

            return min(cand1, cand2);
        } else {
            int max_num_idx = get_max_num_idx(nums);
            int reversed_max_num_idx = (n-1) - max_num_idx;

            // reverse first
            int cand1 = reversed_max_num_idx + 1 + 1; // rotate 1 + reverse 1
            if(cand1 >= n+1) cand1 -= n;

            // rotate first
            int cand2 = max_num_idx + 1;

            return min(cand1, cand2);
        }
    }
};