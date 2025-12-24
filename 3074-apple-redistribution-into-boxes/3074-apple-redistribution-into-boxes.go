func minimumBoxes(apple []int, capacity []int) int {
    sort.Slice(capacity, func(i, j int) bool {
        return capacity[i] > capacity[j]
    })

    sum := 0
    for _, a := range apple {
        sum += a
    }

    i := 0
    for i < len(capacity) && sum > 0 {
        sum -= capacity[i]
        i++
    }

    return i
}