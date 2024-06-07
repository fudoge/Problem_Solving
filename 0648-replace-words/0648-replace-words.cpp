#pragma GCC optimize("03", "unroll-loops")
static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    
    TrieNode() : isEnd(false) {
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    string getPrefix(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                break;
            }
            node = node->children[c - 'a'];
            prefix += c;
            if (node->isEnd) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }
        
        stringstream ss(sentence);
        string word;
        string ans = "";
        
        while (ss >> word) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += trie.getPrefix(word);
        }
        
        return ans;
    }
};