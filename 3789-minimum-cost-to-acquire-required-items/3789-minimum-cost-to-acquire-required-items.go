func minimumCost(cost1 int, cost2 int, costBoth int, need1 int, need2 int) int64 {
    ans := int64(0)
    if costBoth <= cost1 + cost2 {
        le := min(need1, need2)
        ans += int64(le) * int64(costBoth)
        need1 -= le
        need2 -= le
    }    

    if need1 > 0 {
        cost := min(cost1, costBoth)
        ans += int64(need1) * int64(cost)
        need1 = 0
    }

    if need2 > 0 {
        cost := min(cost2, costBoth)
        ans += int64(need2) * int64(cost)
        need2 = 0
    }

    return ans
}