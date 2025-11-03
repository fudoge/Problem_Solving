func minCost(colors string, neededTime []int) int {
	ans := 0
	n := len(colors)

	for i := 0; i < n; {
		j := i + 1
		sum := neededTime[i]
		maximum := neededTime[i]
		for j < n && colors[i] == colors[j] {
			sum += neededTime[j]
			maximum = max(maximum, neededTime[j])
			j++
		}

		ans += (sum - maximum)
		i = j
	}

	return ans
}
