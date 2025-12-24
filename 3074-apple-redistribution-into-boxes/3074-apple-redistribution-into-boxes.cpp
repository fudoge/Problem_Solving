class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<>());
        int sum = accumulate(apple.begin(), apple.end(), 0);
        int i = 0;
        while(i < capacity.size() && sum > 0) {
            sum -= capacity[i];
            i++;
        }

        return i;
    }
};