func pivotArray(nums []int, pivot int) []int {
    le := make([]int, 0)
    eq := make([]int, 0)
    gt := make([]int, 0)

    for _, num := range nums {
        if num < pivot {
            le = append(le, num)
        } else if num == pivot {
            eq = append(eq, num)
        } else {
            gt = append(gt, num)
        }
    }

    return append(le, append(eq, gt...)...)
}