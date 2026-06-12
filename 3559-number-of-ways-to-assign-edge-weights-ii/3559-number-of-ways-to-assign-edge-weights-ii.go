const N int = 100_001
const LOG int = 17
const MOD int = 1_000_000_007

var up [][]int
var adj [][]int
var depth []int
var ways []int 
var isInitialized bool

func initialize() {
    ways = make([]int, N)
    ways[0] = 0
    ways[1] = 1
    for i := 2; i < N; i++ {
        ways[i] = (ways[i-1] * 2) % MOD
    }
    isInitialized = true
}

func dfs(v, parent int) {
    up[v][0] = parent

    for i := 1; i <= LOG; i++ {
        up[v][i] = up[up[v][i-1]][i-1]
    }

    for _, next := range adj[v] {
        if next == parent { continue }
        depth[next] = depth[v] + 1
        dfs(next, v)
    }
}

func lca(u, v int) int {
    if depth[u] < depth[v] {
        u, v = v, u
    }
    diff := depth[u] - depth[v]

    for i := 0; i <= LOG; i++ {
        if diff & (1 << i) != 0 {
            u = up[u][i]
        }
    }

    if u == v { return u }

    for i := LOG; i >= 0; i-- {
        if up[u][i] != up[v][i] {
            u = up[u][i]
            v = up[v][i]
        }
    }

    return up[u][0]
}

func assignEdgeWeights(edges [][]int, queries [][]int) []int {
    if !isInitialized {
        initialize()
    }

    n := len(edges) + 1

    adj = make([][]int, n+1)
    depth = make([]int, n+1)
    up = make([][]int, n+1)
    for i := 0; i <= n; i++ {
        up[i] = make([]int, LOG+1)
    }

    for _, edge := range edges {
        u := edge[0]
        v := edge[1]
        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    depth[1] = 0
    dfs(1, 1)

    ans := make([]int, len(queries))
    for i, query := range queries {
        u := query[0]
        v := query[1]

        ancestor := lca(u, v)
        dist := depth[u] + depth[v] - 2 * depth[ancestor]

        ans[i] = ways[dist]
    }

    return ans
}