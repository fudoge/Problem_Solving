func maxIncreasingSubarrays(nums []int) int {
    n := len(nums)
    k := 1
    laststart := -1
    lastlen := 1
    for i := 0; i < n; i++ {
        j := i+1
        for j < n && nums[j] > nums[j-1] {
            j++
        }
        
        k = max(k, (j-i)/2)
        if laststart + lastlen == i {
            k = max(k, min(lastlen, j-i))
        }
        laststart = i
        lastlen = j - i

        i = j-1
    }

    return k
}