class Solution {
private:
    int ans, n;
public:
    int check(const vector<string>& words, const vector<int>& score, vector<int>& letter_count, int idx) {
        int x = 0;
        for(char ch : words[idx]) {
            int index = ch - 'a';
            if(letter_count[index] <= 0) {
                return -1;
            }
            letter_count[index]--;
            x += score[index];
        }
        return x;
    }

    void solve(const vector<string>& words, const vector<int>& score, vector<int>& letter_count, int idx, int sum) {
        ans = max(ans, sum);
        if(idx >= n) return;

        for(int i = idx; i < n; i++) {
            vector<int> copy = letter_count;
            int x;
            if((x = check(words, score, letter_count, i)) != -1) {
                solve(words, score, letter_count, i+1, sum + x);
            }
            letter_count = copy;
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        ans = 0;
        vector<int> letter_count(26, 0);

        for(char letter : letters) {
            letter_count[letter - 'a']++;
        }

        solve(words, score, letter_count, 0, 0);

        return ans;
    }
};
