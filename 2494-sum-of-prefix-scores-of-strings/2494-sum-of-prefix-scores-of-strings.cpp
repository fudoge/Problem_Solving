class TrieNode {
public:
    char val;
    int cnt;
    TrieNode* children[26];

    TrieNode(char val) {
        this -> val = val;
        cnt = 0;
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('-');
    }

    void addWord(string word) {
        auto curr = root;

        for(char prefix : word) {
            if (curr -> children[prefix - 'a'] == NULL) curr -> children[prefix - 'a'] = new TrieNode(prefix);
            curr = curr -> children[prefix - 'a'];
            curr -> cnt++;
        }
    }

    int getScore(string word) {
        auto curr = root;
        int res = 0;
        for(char prefix : word) {
            curr = curr -> children[prefix - 'a'];
            res += curr -> cnt;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for(const auto &word : words) {
            t -> addWord(word);
        }

        vector<int> ans;
        for(const auto &word : words) {
            ans.push_back(t -> getScore(word));
        }

        return ans;
    }
};