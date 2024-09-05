func missingRolls(rolls []int, mean int, n int) []int {
    m := len(rolls)
    goal := (m + n) * mean

    for _, v := range rolls {
        goal -= v
    }

    if goal < n || goal > 6 * n {
        return make([]int,0)
    }

    ans := make([]int, n, n)
    i := 0
    for i < goal % n {
        ans[i] = (goal / n) + 1
        i++
    }

    for i < n {
        ans[i] = (goal / n)
        i++
    }

    return ans
}