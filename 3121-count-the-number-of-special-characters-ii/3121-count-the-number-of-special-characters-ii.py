class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ans = 0
        for ch, CH in zip(ascii_lowercase, ascii_uppercase):
            if ch not in word or CH not in word: continue
            ans += word.rfind(ch) < word.find(CH)
        
        return ans