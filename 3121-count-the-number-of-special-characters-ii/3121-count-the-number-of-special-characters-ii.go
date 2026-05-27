func numberOfSpecialChars(word string) int {
    lowerLast := make([]int, 26)
    upperFirst := make([]int, 26)

    for i := 0; i < 26; i++ {
        lowerLast[i] = math.MaxInt
        upperFirst[i] = -1
    }

    for i, ch := range word {
        if ch >= 'a' && ch <= 'z' {
            lowerLast[ch-'a'] = i
        } else {
            ord := ch-'A'
            if upperFirst[ord] == -1 {
                upperFirst[ord] = i
            }
        }
    }

    ans := 0
    for i := 0; i < 26; i++ {
        if lowerLast[i] < upperFirst[i] {
            ans++
        }
    }
    return ans
}