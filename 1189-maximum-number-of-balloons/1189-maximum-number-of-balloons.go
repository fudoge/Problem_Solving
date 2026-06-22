func maxNumberOfBalloons(text string) int {
    table := make([]int, 26)    
    for _, ch := range text {
        table[ch-'a']++
    }

    bCount := table['b'-'a']
    aCount := table['a'-'a']
    lCount := table['l'-'a'] / 2
    oCount := table['o'-'a'] / 2
    nCount := table['n'-'a']

    return min(bCount, aCount, lCount, oCount, nCount) 
}