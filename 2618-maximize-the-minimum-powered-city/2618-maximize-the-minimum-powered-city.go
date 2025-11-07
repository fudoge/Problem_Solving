type Solver struct {
	n    int
	r    int
	k    int64
	pref []int64
}

func NewSolver(stations []int, r int, k int) *Solver {
	n := len(stations)
	pref := make([]int64, n)
	pref[0] = int64(stations[0])
	for i := 1; i < n; i++ {
		pref[i] = pref[i-1] + int64(stations[i])
	}
	return &Solver{n, r, int64(k), pref}
}

func (s *Solver) check(target int64) bool {
	added := make([]int64, s.n)
	extraSum := int64(0)
	k := s.k

	for i := 0; i < s.n; i++ {
		leftIdx := max(i-s.r-1, 0)
		rightIdx := min(i+s.r, s.n-1)
		var left int64
		if i-s.r-1 >= 0 {
			left = s.pref[leftIdx]
		} else {
			left = 0
		}
		right := s.pref[rightIdx]
		extraSum -= added[leftIdx]
		sum := right - left + extraSum

		diff := target - sum
		if diff > 0 {
			if k-diff < 0 {
				return false
			}
			added[rightIdx] += diff
			extraSum += diff
			k -= diff
		}
	}

	return true
}

func (s *Solver) solve() int64 {
	var res int64
	lo, hi := int64(0), s.pref[s.n-1]+s.k
	for lo <= hi {
		mid := (lo + hi) >> 1
		if s.check(mid) {
			res = mid
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}

	return res
}

func maxPower(stations []int, r int, k int) int64 {
	s := NewSolver(stations, r, k)

	return s.solve()
}
