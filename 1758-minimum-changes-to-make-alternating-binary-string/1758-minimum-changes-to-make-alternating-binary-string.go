func calc(s string, start int) int {
    res := 0
    goal := start

    for _. ch := range s {
        if byte(ch) - '0' != goal {
            res++
        }
        goal ^= 1
    }

    return res
}

func minOperations(s string) int {
    ops := calc(s, 0)
    return min(len(s) - ops) 
}