func xorQueries(arr []int, queries [][]int) []int {
    ans := make([]int, len(queries))
    table := make([]int, len(arr))
    table[0] = arr[0]

    for i := 1; i < len(arr); i++ {
        table[i] = table[i-1] ^ arr[i]
    }

    for i, query := range queries {
        from := query[0]
        to := query[1]

        if from == 0 {
            ans[i] = table[to]
        } else {
            ans[i] = table[to] ^ table[from-1]
        }
    }

    return ans
}