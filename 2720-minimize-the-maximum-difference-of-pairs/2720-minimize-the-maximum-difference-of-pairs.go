func check(maxDiff, p int, nums []int) bool {
    i := 0
    cnt := 0
    for i < len(nums)-1 {
        if nums[i+1] - nums[i] <= maxDiff {
            cnt++
            i += 2
        } else {
            i++
        }
    }

    return cnt >= p
}

func minimizeMax(nums []int, p int) int {
    sort.Ints(nums)
    lo, hi := 0, 1_000_000_000    

    ans := math.MaxInt
    for lo <= hi {
        mid := (lo + hi) >> 1
        if check(mid, p, nums) {
            ans = mid
            hi = mid-1
        } else {
            lo = mid+1
        }
    }

    return ans
}