const MOD int = 1_000_000_007

func zigZagArrays(n int, l int, r int) int {
    m := r-l+1

    if n == 1 { return m }

    up := make([]int, m)
    down := make([]int, m)

    for x := 0; x < m; x++ {
        up[x] = x
        down[x] = m-1-x
    }

    for len := 3; len <= n; len++ {
        prefUp := make([]int, m)
        prefDown := make([]int, m)

        prefUp[0] = up[0]
        prefDown[0] = down[0]

        for x := 1; x < m; x ++ {
            prefUp[x] = (prefUp[x-1] + up[x]) % MOD
            prefDown[x] = (prefDown[x-1] + down[x]) % MOD
        }

        totalUp := prefUp[m-1]
        newUp := make([]int, m)
        newDown := make([]int, m)

        for x := 0; x < m; x++ {
            if x > 0 {
                newUp[x] = prefDown[x-1]
            }

            newDown[x] = (totalUp - prefUp[x] + MOD) % MOD
        }

        up = newUp
        down = newDown
    }

    ans := 0
    for x := 0; x < m; x++ {
        ans = (ans + up[x] + down[x]) % MOD
    }

    return ans
}