class Solution {
public:
    int maxVowels(string s, int k) {
        int max;
        int current = 0;
        deque<char> substring;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0; i < k; i++){
            substring.push_back(s[i]);
            if(vowels.count(s[i])){
                current++;
            }
        }
        max = current;

        for(int i = k; i < s.length(); i++){
            if(vowels.count(substring.front())){
                current--;
            }
            substring.pop_front();
            substring.push_back(s[i]);
            if(vowels.count(s[i])){
                current++;
            }
            if(current > max){
                max = current;
            }
        }
        return max;
    }
};