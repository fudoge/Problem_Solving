type Solver struct {
	fact [11]int64
}

func (s *Solver) initFactorial() {
	s.fact[0] = 1
	for i := 1; i <= 10; i++ {
		s.fact[i] = s.fact[i-1] * int64(i)
	}
}
func (s *Solver) generate(l int, arr []int, res *[][]int) {
	if len(arr) == l {
		cpy := make([]int, l)
		copy(cpy, arr)
		*res = append(*res, cpy)
		return
	}
	for i := 0; i <= 9; i++ {
		s.generate(l, append(arr, i), res)
	}
}

func (s *Solver) getPalindromes(n int) [][]int {
	l := n/2 + n%2
	var res [][]int
	for i := 1; i <= 9; i++ {
		s.generate(l, []int{i}, &res)
	}
	return res
}

func (s *Solver) getKPalindromes(n, k int, pals [][]int) []int64 {
	unique := make(map[int64]struct{})
	for _, half := range pals {
		l := n/2 + n%2
		if len(half) != l {
			continue
		}
		var full int64 = 0
		for _, d := range half {
			full = full*10 + int64(d)
		}
		start := len(half) - 1
		if n%2 == 1 {
			start--
		}
		for i := start; i >= 0; i-- {
			full = full*10 + int64(half[i])
		}
		if full%int64(k) == 0 {
			unique[full] = struct{}{}
		}
	}
	var res []int64
	for num := range unique {
		res = append(res, num)
	}
	return res
}
func (s *Solver) getCount(n int, pat int64) int64 {
	total := s.fact[n]
	for i := 0; i < 10; i++ {
		freq := (pat >> (i * 4)) & 15
		total /= s.fact[freq]
	}

	zeroCount := (pat >> 0) & 15
	if zeroCount == 0 {
		return total
	}

	invalid := s.fact[n-1]
	for i := 0; i < 10; i++ {
		freq := (pat >> (i * 4)) & 15
		if i == 0 {
			freq--
		}
		invalid /= s.fact[freq]
	}
	return total - invalid
}


func countGoodIntegers(n int, k int) int64 {
	if n == 1 {
		var ans int64 = 0
		for i := 1; i <= 9; i++ {
			if i%k == 0 {
				ans++
			}
		}
		return ans
	}

	s := Solver{}
	s.initFactorial()
	pals := s.getPalindromes(n)
	kpals := s.getKPalindromes(n, k, pals)

	patterns := make(map[int64]struct{})
	for _, val := range kpals {
		var pat int64 = 0
		count := [10]int{}
		for x := val; x > 0; x /= 10 {
			count[x%10]++
		}
		for i := 0; i < 10; i++ {
			pat |= int64(count[i]) << (i * 4)
		}
		patterns[pat] = struct{}{}
	}

	var ans int64 = 0
	for pat := range patterns {
		ans += s.getCount(n, pat)
	}
	return ans
}