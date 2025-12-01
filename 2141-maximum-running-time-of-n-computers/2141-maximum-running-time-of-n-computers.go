func maxRunTime(n int, batteries []int) int64 {
	ans := int64(0)
	lo := int64(0)
	hi := int64(0)
	for _, bat := range batteries {
		hi += int64(bat)
	}
	hi /= int64(n)

	for lo <= hi {
		mid := (lo + hi) >> 1
		if check(mid, n, batteries) {
			ans = mid
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	return ans
}

func check(time int64, n int, batteries []int) bool {
	tot := int64(0)

	for _, b := range batteries {
		tot += min(int64(b), time)
	}

	return tot >= time*int64(n)
}
