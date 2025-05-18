const MOD int64 = 1_000_000_007

type MatState struct {
    states [][]int
    adj [][]bool
    numStates int
    numColors int
    m int
    n int
}

func NewMS(m, n int) *MatState {
    return &MatState{m:m, n:n, numColors:3} 
}

func (MS *MatState) Generate() {
    temp := make([]int, 0)
    MS.dfs(temp)
    MS.numStates = len(MS.states)

    MS.adj = make([][]bool, MS.numStates)
    for i := 0; i < MS.numStates; i++ {
        MS.adj[i] = make([]bool, MS.numStates)
    }

    for i := 0; i < MS.numStates; i++ {
        for j := 0; j < MS.numStates; j++ {
            flag := true
            for k := 0; k < MS.m; k++ {
                if MS.states[i][k] == MS.states[j][k] {
                    flag = false
                    break
                }
            }
            if flag {
                MS.adj[i][j] = true
                MS.adj[j][i] = true
            }
        }
    }
}

func (MS *MatState) dfs(temp []int) {
    if len(temp) == MS.m {
        state := make([]int, MS.m)
        copy(state, temp)
        MS.states = append(MS.states, state)
        return
    }

    for i := 0; i < MS.numColors; i++ {
        if len(temp) == 0 || temp[len(temp)-1] != i {
            temp = append(temp, i)
            MS.dfs(temp)
            temp = temp[0:len(temp)-1]
        }
    }
}

func colorTheGrid(m int, n int) int {
    MS := NewMS(m, n) 
    MS.Generate()

    dp := make([][]int64, n+1)
    for i := 0; i <= n; i++ {
        dp[i] = make([]int64, MS.numStates)
    }

    for state := 0; state < MS.numStates; state++ {
        dp[1][state] = 1
    }

    for i := 2; i <= n; i++ {
        for curState := 0; curState < MS.numStates; curState++ {
            for lastState := 0; lastState < MS.numStates; lastState++ {
                if MS.adj[curState][lastState] {
                    dp[i][curState] = (dp[i][curState] + dp[i-1][lastState]) % MOD
                }
            }
        }
    }

    ans := int64(0)
    for i := 0; i < MS.numStates; i++ {
        ans = (ans + dp[n][i]) % MOD
    }

    return int(ans)
}