const MOD int = 1e9 + 7

func specialTriplets(nums []int) int {
    n := len(nums)
    lTable := make([]int, 200001) 
    rTable := make([]int, 200001) 

    for _, num := range nums {
        rTable[num]++
    }
    rTable[nums[0]]--
    lTable[nums[0]]++

    ans := 0
    for j := 1; j < n-1; j++ {
        rTable[nums[j]]--
        target := nums[j] * 2
        ans = (ans + lTable[target] * rTable[target]) % MOD
        lTable[nums[j]]++
    } 
    return ans
}