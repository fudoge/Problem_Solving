func maxDifference(s string) int {
    freq := make([]int, 26)
    for _, ch := range s {
        freq[ch - 'a']++
    }

    maxOdd := math.MinInt
    minEven := math.MaxInt
    for i := 0; i < 26; i++ {
        if freq[i] == 0 {
            continue
        }
        if freq[i] % 2 == 1 {
            maxOdd = max(maxOdd, freq[i])
        } else {
            minEven = min(minEven, freq[i])
        }
    }

    return maxOdd - minEven
}