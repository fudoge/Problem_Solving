func repeatedNTimes(nums []int) int {
    n2 := len(nums)
    freq := make([]int, 10001) 
    for _, num := range nums {
        freq[num]++ 
        if freq[num] >= n2/2 {
            return num
        }
    }

    return -1
}