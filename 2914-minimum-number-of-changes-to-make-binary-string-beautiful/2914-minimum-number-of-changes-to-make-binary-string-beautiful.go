func minChanges(s string) int {
    n := len(s)    
    ans := 0
    for i := 0; i < n; i += 2 {
        if s[i] != s[i+1] {
            ans++
        }
    }
    return ans
}