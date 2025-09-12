func minimumDeletions(word string, k int) int {
    freq := make([]int, 26)  
    for _, ch := range word {
        freq[ch-'a']++
    } 

    sort.Ints(freq)
    pref := make([]int, 26)
    pref[0] = freq[0]
    for i := 1; i < 26; i++ {
        pref[i] = pref[i-1] + freq[i]
    }

    right := 0
    ans := math.MaxInt
    for left := 0; left < 26; left ++ {
        for right < 26 && freq[right] - freq[left] <= k {
            right++
        }
        leftDel, rightDel := 0, 0
        if left > 0 {
            leftDel = pref[left-1]
        }
        if right < 26 {
            rightDel = (pref[25] - pref[right-1]) - (26 - right) * (freq[left] + k)
        }

        ans = min(ans, leftDel + rightDel)
    }
    return ans
}