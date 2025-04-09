func minOperations(nums []int, k int) int {
    mp := make(map[int]bool)    
    minima := int(1e9)
    for _, num := range nums {
        mp[num] = true
        minima = min(minima, num)
    }
    if minima < k {
        return -1
    } 

    if minima > k {
        return len(mp)
    }
    return len(mp)-1
}