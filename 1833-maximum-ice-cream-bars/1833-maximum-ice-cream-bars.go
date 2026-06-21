const MAXN int = 100_000 
func maxIceCream(costs []int, coins int) int {
    table := make([]int, MAXN+1)
    for _, cost := range costs {
        table[cost]++
    }

    ans := 0
    for cost := 1; cost <= MAXN; cost++ {
        count := table[cost]
        if count * cost > coins {
            available := coins / cost
            coins -= available * cost
            ans += available
            break
        }
        coins -= count * cost
        ans += count
    }

    return ans
}