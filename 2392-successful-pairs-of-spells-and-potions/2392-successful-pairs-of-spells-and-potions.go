func successfulPairs(spells []int, potions []int, success int64) []int {
    n := len(spells)
    m := len(potions)
    sort.Ints(potions)

    res := make([]int, n)
    for i := 0; i < n; i++ {
        res[i] = m - lowerBound(potions, success, spells[i])
    }

    return res
}

func lowerBound(potions []int, success int64, spell int) int {
    l, r := 0, len(potions)-1
    res := len(potions)
    for l <= r {
        mid := (l + r) >> 1
        if int64(potions[mid]) * int64(spell) >= success {
            res = mid
            r = mid - 1
        } else {
            l = mid + 1
        }
    } 

    return res
}