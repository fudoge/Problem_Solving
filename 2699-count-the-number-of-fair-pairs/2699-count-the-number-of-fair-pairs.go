func lowerBound(x, l, r int, nums []int) int {

	for l <= r {
		mid := (l + r) >> 1
		if nums[mid] >= x {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}

	return l
}
func countFairPairs(nums []int, lower int, upper int) int64 {
    ans := int64(0)
    sort.Ints(nums)
    for i, num := range nums {
        l := lower - num
        u := upper - num

        llb := lowerBound(l,i+1, len(nums)-1, nums)
        rlb := lowerBound(u+1, i+1, len(nums)-1, nums)

        if rlb > llb {
            ans += int64(rlb - llb)
        }
    }
    return ans
}
