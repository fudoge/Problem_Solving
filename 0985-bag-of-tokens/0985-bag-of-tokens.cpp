class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        const int n = tokens.size();
        int score = 0, maxScore = 0;
        int left = 0, right = n-1;

        while(left <= right) {
            // Face Up:
            if(power >= tokens[left]) {
                power -= tokens[left];
                left++;
                score++;
                maxScore = max(maxScore, score);
                continue;
            }

            // Face Down:
            if(score > 0) {
                power += tokens[right];
                right--;
                score--;
                continue;
            }

            break;
        }
        return maxScore;
    }
};