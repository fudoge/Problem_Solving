class TrieNode {
public:
    int data;
    bool isTerminal;
    TrieNode* children[10];

    TrieNode(int ch) {
        data = ch;
        isTerminal = false;
        for(int i = 0; i < 10; ++i) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(-1);
    }

    void insert(int data) {
        auto node = root;

        int divisor = 1;
        while (data / divisor >= 10) {
            divisor *= 10;
        }

        while (divisor > 0) {
            int digit = (data / divisor) % 10;
            if (node->children[digit] == NULL) {
                node->children[digit] = new TrieNode(digit);
            }
            node = node->children[digit];
            divisor /= 10;
        }
        node->isTerminal = true;
    }

    int prefixLen(int data) {
        auto node = root;
        int len = 0;
        int divisor = 1;
        while (data / divisor >= 10) {
            divisor *= 10;
        }

        while (divisor > 0) {
            int digit = (data / divisor) % 10;
            if (node->children[digit] == nullptr) {
                return len;
            } else {
                len++;
                node = node->children[digit];
                divisor /= 10;
            }
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();
        for(int num : arr2) {
            t -> insert(num);
        }

        int ans = 0;
        for(int num : arr1) {
            ans = max(ans, t -> prefixLen(num));
        }

        return ans;
    }
};