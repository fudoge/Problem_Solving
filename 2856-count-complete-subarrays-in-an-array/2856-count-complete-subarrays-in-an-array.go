func countCompleteSubarrays(nums []int) int {
    s := make(map[int]int) 
    for _, num := range nums {
        s[num]++
    }
    
    completeSize := len(s) 
    left := 0
    elems := 0
    ans := 0
    freq := make(map[int]int)
    for right, num := range nums {
        freq[num]++
        if freq[num] == 1 {
            elems++
        }
        for left <= right && elems == completeSize {
            freq[nums[left]]--;
            if freq[nums[left]] == 0 {
                elems--
            }
            left++
        }

        ans += left
    }
    return ans
}