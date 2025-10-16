func findSmallestInteger(nums []int, value int) int {
    freq := make([]int, value)
    for _, num := range nums {
        number := num % value
        if number < 0 {
            number += value
        }
        freq[number]++
    } 

    minCount := math.MaxInt
    minNum := -1
    for i, _ := range freq {
        if freq[i] < minCount {
            minCount = freq[i]
            minNum = i
        }
    }

    return minCount * value + minNum
}