#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    vector<string> split(string &sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> arr;
        while(ss >> word) {
            arr.push_back(word);
        }
        return arr;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto arr1 = split(sentence1);
        auto arr2 = split(sentence2);

        if(arr1.size() > arr2.size()) swap(arr1, arr2);

        int n = arr1.size();
        int m = arr2.size();

        int left = 0, right = n-1;
        while(left < n && arr1[left] == arr2[left]) left++;
        while(right >= 0 && arr1[right] == arr2[right + m - n]) right--;

        return left > right;
    }
};