class Solution {
public:
    bool halvesAreAlike(string s) {
        const int n = s.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int a = 0,b=0;

        for(int i = 0; i < n/2; i++) {
            if(vowels.find(s[i]) != vowels.end()) a++;
        }

        for(int i = n/2; i < n; i++) {
            if(vowels.find(s[i]) != vowels.end()) b++;
        }
        cout << a << " " << b;
        return a == b;
    }
};