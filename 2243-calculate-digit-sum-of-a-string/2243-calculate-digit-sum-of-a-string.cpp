class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string next = "";

            int streak = 0;
            int sum = 0;
            for(int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';
                streak++;
                if(streak >= k) {
                    next += to_string(sum);
                    sum = 0;
                    streak = 0;
                }
            }
            if(streak >= 1) {
                next += to_string(sum);
                sum = 0;
                streak = 0;
            }

            s = next;
        }

        return s;
    }
};