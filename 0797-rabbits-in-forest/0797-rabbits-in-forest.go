func numRabbits(answers []int) int {
    freq := make(map[int]int)    
    for _, a := range answers {
        freq[a]++
    }

    res := 0
    for k, v := range freq {
        groupSize := k+1
        groups := (v+k)/groupSize
        res += groupSize * groups
    }
    return res
}