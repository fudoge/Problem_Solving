func minDeletionSize(strs []string) int {
    n := len(strs)
    m := len(strs[0])

    ans := 0
    sorted := make([]bool, n-1)    
    for j := 0; j < m; j++ {
        flag := false
        temp := make([]bool, n-1)
        copy(temp, sorted)
        for i := 0; i < n-1; i++ {
            if !sorted[i] {
                if strs[i][j] > strs[i+1][j] {
                    flag = true
                    break
                } else if strs[i][j] < strs[i+1][j] {
                    temp[i] = true
                }
            }
        }

        if flag {
            ans++
        } else {
            copy(sorted, temp)
        }
    }

    return ans
}