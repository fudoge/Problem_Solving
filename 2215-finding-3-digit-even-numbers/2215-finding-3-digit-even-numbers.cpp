class Solution {
public:
    bool isAble(vector<int> &freq, int num) {
        bool flag = true;
        int d1 = (num % 1000) / 100;
        int d2 = (num%100) / 10;
        int d3 = num%10;

        freq[d1]--;
        freq[d2]--;
        freq[d3]--;
        if(freq[d1] < 0 || freq[d2] < 0 || freq[d3] < 0) flag = false;
        freq[d1]++;
        freq[d2]++;
        freq[d3]++;

        return flag;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10), ans;

        for(const auto &digit : digits) {
            freq[digit]++;
        }

        for(int i = 100; i < 1000; i+=2) {
            if(isAble(freq, i)) ans.emplace_back(i);
        } 

        return ans;
    }
};