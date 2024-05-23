class Solution {
public:
    static int bitcount(int n) {
        int count = 0;
        while(n > 0) {
            if(n % 2 == 1) count++;
            n /= 2;
        }
        return count;
    }

    static bool comp(int a, int b) {
        int countA = bitcount(a);
        int countB = bitcount(b);
        
        if(countA == countB) return a < b;
        else return countA < countB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};