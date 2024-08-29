type union struct {
    rank   []int
    parent []int
}

func (u *union) find(x int) int {
    if u.parent[x] != x {
        u.parent[x] = u.find(u.parent[x])
    }
    return u.parent[x]
}

func (u *union) unionSets(x, y int) {
    rootX := u.find(x)
    rootY := u.find(y)

    if rootX != rootY {
        if u.rank[rootX] > u.rank[rootY] {
            u.parent[rootY] = rootX
            u.rank[rootX] += u.rank[rootY]
        } else {
            u.parent[rootX] = rootY
            if u.rank[rootX] == u.rank[rootY] {
                u.rank[rootY]++
            }
        }
    }
}

func removeStones(stones [][]int) int {
    n := len(stones)
    
    maxRow, maxCol := 0, 0
    for _, stone := range stones {
        if stone[0] > maxRow {
            maxRow = stone[0]
        }
        if stone[1] > maxCol {
            maxCol = stone[1]
        }
    }
    
    u := union{
        rank:   make([]int, maxRow+maxCol+2),
        parent: make([]int, maxRow+maxCol+2),
    }

    for i := 0; i <= maxRow+maxCol+1; i++ {
        u.parent[i] = i
    }

    for _, stone := range stones {
        row := stone[0]
        col := stone[1] + maxRow + 1
        u.unionSets(row, col)
    }

    uniqueParents := make(map[int]struct{})
    for _, stone := range stones {
        root := u.find(stone[0])
        uniqueParents[root] = struct{}{}
    }

    return n - len(uniqueParents)
}