func chalkReplacer(chalk []int, k int) int {
    var total int64

    for _, c := range chalk {
        total += int64(c)
    }
    k = int(int64(k) % total)

    for i, v := range chalk {
        if v > k {
            return i
        }
        k -= v
    }
    return 0
}