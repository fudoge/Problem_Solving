const MOD int = 1e9 + 7

func getIntervals(fences []int) map[int]int {
    intervals := make(map[int]int)
    for i := 0; i < len(fences); i++ {
        for j := i+1; j < len(fences); j++ {
            diff := fences[j] - fences[i]
            intervals[diff]++
        }
    }
    return intervals
}

func maximizeSquareArea(m int, n int, hFences []int, vFences []int) int {
    hFences = append(hFences, 1)    
    hFences = append(hFences, m)    
    vFences = append(vFences, 1)    
    vFences = append(vFences, n)    
    sort.Ints(hFences)
    sort.Ints(vFences)

    hIntervals := getIntervals(hFences)
    vIntervals := getIntervals(vFences)

    side := -1
    for cand, _ := range hIntervals {
        if _, ok := vIntervals[cand]; ok {
            side = max(side, cand)
        }
    }

    if side == -1 {
        return -1
    }

    return side * side % MOD
}