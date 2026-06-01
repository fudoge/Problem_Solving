func minimumCost(cost []int) int {
    sort.Ints(cost)    

    ans := 0
    cnt := 0;
    for i := len(cost)-1; i >= 0; i-- {
        if cnt == 2 {
            cnt = 0
        } else {
            ans += cost[i]
            cnt++
        }
    }

    return ans
}