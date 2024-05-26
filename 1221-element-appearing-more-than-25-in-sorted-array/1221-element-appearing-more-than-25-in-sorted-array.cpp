class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int n = arr.size();
        int streak = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i-1]) streak++;
            else streak = 1;
            if(streak > n/4) return arr[i];
        }
        return arr[0];
    }
};