class Solution {
private:
    int dfs(const string &suffix, vector<string> &dictionary, unordered_map<int, int> &cache) {
        int len = suffix.size();
        if(len == 0) return 0;

        if(cache.find(len) != cache.end()) return cache[len];

        int minimum = len;
        for(const auto &word : dictionary) {
            if(suffix.substr(0, word.size()) == word){
                minimum = min(minimum, dfs(suffix.substr(word.size()), dictionary, cache));
            }
        }

        minimum = min(minimum, 1 + dfs(suffix.substr(1), dictionary, cache));

        cache[len] = minimum;
        return minimum;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<int, int> cache;

        return dfs(s, dictionary, cache);
    }
};