class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            int root = sqrt(num);
            int cnt = 0;
            int sum = 1 + num;
            for(int i = 2; i <= root; i++) {
                if(num % i == 0) {
                    if(i * i == num) cnt++;
                    else cnt+=2;
                    sum += i + num / i;
                }
            }
            if(cnt == 2) ans += sum;
        }       
        return ans;
    }
};