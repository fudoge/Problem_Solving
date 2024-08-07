#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    vector<string> numWords = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tys = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string convert(int digit, vector<int>& nums) {
        string res = "";

        // 100
        if(nums[digit+2] != 0) {
            res += (numWords[nums[digit+2]] + " Hundred ");
        }

        // 0 ~ 99
        if(nums[digit+1] == 0) {
            res += numWords[nums[digit]];
            if(nums[digit]) res += " ";
        } else if(nums[digit+1] == 1) {
            res += teens[nums[digit]];
            res += " ";
        } else {
            res += tys[nums[digit+1]];
            if(nums[digit]) {
                res += " ";
                res += numWords[nums[digit]];
            }
            res += " ";
        }

        return res;
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<int> nums;
        while(num > 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        while(nums.size() < 10) {
            nums.push_back(0);
        }
        string n = convert(6, nums);
        string m = convert(3, nums);

        string ans = (nums[9]? numWords[nums[9]] + " Billion ":"") + (n!=""? n + "Million ":"") + (m!=""? m + "Thousand ":"") + convert(0, nums);

        ans.pop_back();
        return ans;
    }
};