class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower_last = [1e9] * 26
        upper_first = [-1] * 26

        for i, ch in enumerate(word):
            if ch >= 'a' and ch <= 'z':
                lower_last[ord(ch) - ord('a')] = i
            else:
                ch_ord = ord(ch)-ord('A')
                if upper_first[ch_ord] == -1:
                    upper_first[ch_ord] = i
            
        
        ans = 0
        for i in range(0, 26):
            if lower_last[i] < upper_first[i]:
                ans += 1
        
        return ans
