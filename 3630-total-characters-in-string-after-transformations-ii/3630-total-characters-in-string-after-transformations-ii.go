const MOD int64 = 1_000_000_007

type Matrix [][]int64
func newMatrix(r, c int) Matrix {
    m := make(Matrix, r)
    for i:= range m {
        m[i] = make([]int64, c)
    }
    return m
}
func matMul(a, b Matrix) Matrix {
    n, m, l := len(a), len(b[0]), len(b)
    res := newMatrix(n, m)
    for i := 0; i < n; i++ {
        for k := 0; k < l; k++ {
            for j := 0; j < m; j++ {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD   
            }
        }
    }
    return res
}
func bpow(base Matrix, exp int64) Matrix {
    n := len(base)
    res := newMatrix(n, n)
    for i := 0; i < n; i++ {
        res[i][i] = 1
    }
    for exp > 0 { 
        if exp%2 == 1 {
            res = matMul(res, base)
        }
        exp >>= 1;
        base = matMul(base, base)
    }

    return res
}

func lengthAfterTransformations(s string, t int, nums []int) int {
    T := newMatrix(26, 26) 
    freq := newMatrix(1, 26)

    for i := 0; i < 26; i++ {
        for d := 1; d <= nums[i]; d++ {
            j := (i + d) % 26
            T[i][j]++
        }
    }
    for _, ch := range s {
        freq[0][ch-'a']++
    }

    Tt := bpow(T, int64(t))
    res := matMul(freq, Tt)

    ans := int64(0)
    for i := 0; i < 26; i++ {
        ans = (ans + res[0][i]) % MOD
    }

    return int(ans)
}