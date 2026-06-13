func mapWordWeights(words []string, weights []int) string {
    ans := ""
    for _, word := range words {
        acc := 0
        for _, ch := range word {
            acc += weights[ch-'a']
        }
        acc %= 26
        ans += string('a' + (25-acc))
    }

    return ans
}