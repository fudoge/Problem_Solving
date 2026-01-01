func plusOne(digits []int) []int {
    n := len(digits)
    for i := n-1; i >= 0; i-- {
        digits[i]++
        if digits[i] >= 10 {
            digits[i] %= 10;
            if i == 0 {
                digits = slices.Insert(digits, 0, 1)
            }
        } else {
            break
        }
    }
    return digits
}