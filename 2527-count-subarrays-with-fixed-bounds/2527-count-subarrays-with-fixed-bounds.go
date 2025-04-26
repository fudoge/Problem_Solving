func countSubarrays(nums []int, minK int, maxK int) int64 {
    ans := int64(0)
    lastmK, lastMk, lastInvalid := -1, -1, -1
    for i, num := range nums {
        if num < minK || num > maxK {
            lastInvalid = i
        }
        if num == minK {
            lastmK = i
        }
        if num == maxK {
            lastMk = i
        }

        validStart := min(lastmK, lastMk)
        if validStart > lastInvalid {
            ans += int64(validStart - lastInvalid)
        }
    }
    return ans
}