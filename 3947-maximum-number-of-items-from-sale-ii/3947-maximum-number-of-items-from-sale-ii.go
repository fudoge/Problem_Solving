func maximumSaleItems(items [][]int, budget int) int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][1] < items[j][1]
    })

    mx := 0
    for _, item := range items {
        mx = max(mx, item[0])
    }

    freq := make([]int, mx+1)
    for _, item := range items {
        freq[item[0]]++
    }

    for i := 1; i <= mx; i++ {
        if freq[i] > 0 {
            for j := 2 * i; j <= mx; j += i {
                freq[i] += freq[j]
            }
        }
    }

    mn := items[0][1]
    ans := 0

    for _, item := range items {
        factor, price := item[0], item[1]

        if price - mn > mn {
            break
        }

        cnt := freq[factor] - 1
        takes := min(cnt, budget / price)

        ans += 2 * takes
        budget -= takes * price
    }

    ans += budget / mn

    return ans
}