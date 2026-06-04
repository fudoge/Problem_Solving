func totalWaviness(num1 int, num2 int) int {
    ans := 0
    for i := num1; i <= num2; i++ {
        if i < 100 { continue }
        digits := make([]int, 0)
        num := i
        for num > 0 {
            digits = append(digits, num%10)
            num /= 10
        }
        for j := 1; j < len(digits)-1; j++ {
            if digits[j] > digits[j-1] && digits[j] > digits[j+1] { ans++ }
            if digits[j] < digits[j-1] && digits[j] < digits[j+1] { ans++ }
        }
    }

    return ans
}