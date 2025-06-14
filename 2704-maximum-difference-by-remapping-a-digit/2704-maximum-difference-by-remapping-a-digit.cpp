class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        int maximum = 0;
        for(char i = '0'; i < '9'; i++) {
            string ss = s;
            for(int j = 0; j < ss.size(); j++) {
                if(ss[j] == i) {
                    ss[j] = '9';
                }
            } 
            maximum = max(maximum, stoi(ss));
        }

        int minimum = INT_MAX;
        for(char i = '1'; i <= '9'; i++) {
            string ss = s;
            for(int j = 0; j < ss.size(); j++) {
                if(ss[j] == i) {
                    ss[j] = '0';
                }
            }
            minimum = min(minimum, stoi(ss));
        }
        return maximum - minimum;
    }
};