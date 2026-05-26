func numberOfSpecialChars(word string) int {
    lower := make([]int, 26) 
    upper := make([]int, 26) 

    for _, ch := range word {
        if ch >= 'a' && ch <= 'z' {
            lower[ch - 'a']++
        } else {
            upper[ch - 'A']++
        }
    }

    ans := 0
    for i := 0; i < 26; i++ {
        if lower[i] > 0 && upper[i] > 0 {
            ans++
        }
    }
    return ans
}