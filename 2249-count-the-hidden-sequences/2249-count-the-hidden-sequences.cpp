class Solution {
   public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long x = 0;
        long long maxX = 0;
        long long minX = 0;
        for (const auto& difference : differences) {
            x += difference;
            maxX = max(maxX, x);
            minX = min(minX, x);
        }

        long long start = lower - minX;
        long long end = upper - maxX;

        return start > end ? 0 : end - start + 1;
    }
};