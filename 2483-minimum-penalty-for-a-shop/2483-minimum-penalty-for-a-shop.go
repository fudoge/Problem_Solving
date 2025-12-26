func bestClosingTime(customers string) int {
    best := 0
    for _, c := range customers {
        if c == 'Y' {
            best++
        }
    }

    ans := 0
    curr := best
    for i := 1; i <= len(customers); i++ {
        if customers[i-1] == 'Y' {
            curr--
        } else {
            curr++
        }
        if curr < best {
            curr = best
            ans = i
        }
    }

    return ans
}