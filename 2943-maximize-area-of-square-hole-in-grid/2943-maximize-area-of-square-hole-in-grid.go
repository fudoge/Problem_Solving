func getMaxLen(bars []int) int {
    r := 1
    i := 0
    for i < len(bars) {
        l := i
        for i+1 < len(bars) && bars[i] + 1 == bars[i+1] {
            i++
        }
        r = max(r, i - l + 2)
        i++
    }
    return r
}

func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
    sort.Ints(hBars)
    sort.Ints(vBars)
    h := getMaxLen(hBars)
    v := getMaxLen(vBars)
    side := min(h, v)
    return side * side
}