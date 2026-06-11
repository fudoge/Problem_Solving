const MOD int64 = 1000000007

func bpow(base, exp int64) int64 {
    res := int64(1)
    for exp > 0 {
        if exp & 1 == 1 {
            res = res * base % MOD
        }
        base = base * base % MOD
        exp >>= 1
    }
    return res
}

func assignEdgeWeights(edges [][]int) int {

    adj := make(map[int][]int)
    for _, edge := range edges {
        u := edge[0]
        v := edge[1]

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    q := make([]int, 0, 1)
    visited := make(map[int]bool)
    q = append(q, 1)
    visited[1] = true
    maxDepth := int64(-1)
    for len(q) > 0 {
        l := len(q)
        maxDepth++
        for i := 0; i < l; i++ {
            curr := q[0]
            q = q[1:]
            for _, next := range adj[curr] {
                if v, exists := visited[next]; !v || !exists {
                    visited[next] = true
                    q = append(q, next)
                }
            }
        }
    }

    return int(bpow(2, maxDepth-1))
}