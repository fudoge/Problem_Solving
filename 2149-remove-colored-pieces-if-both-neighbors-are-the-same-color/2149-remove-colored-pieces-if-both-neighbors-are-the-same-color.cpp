class Solution {
public:
    bool winnerOfGame(string colors) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int countA = 0;
        int countB = 0;
        const int n = colors.size();
        for (int i = 1; i < n - 1; i++) {
            if (colors[i-1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
                countA++;
            }
            if (colors[i-1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') {
                countB++;
            }
        }
        return countA > countB;
    }
};