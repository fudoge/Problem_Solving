func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
	startStr := strconv.FormatInt(start-1, 10)
	finishStr := strconv.FormatInt(finish, 10)
	return calc(finishStr, s, limit) - calc(startStr, s, limit)
}

func calc(x string, s string, limit int) int64 {
	if len(x) < len(s) {
		return 0
	}
	if len(x) == len(s) {
		if x >= s {
			return 1
		}
		return 0
	}

	suffix := x[len(x)-len(s):]
	var count int64 = 0
	prefLen := len(x) - len(s)

	for i := 0; i < prefLen; i++ {
		digit := int(x[i] - '0')
		if limit < digit {
			count += int64(math.Pow(float64(limit+1), float64(prefLen-i)))
			return count
		}
		count += int64(digit) * int64(math.Pow(float64(limit+1), float64(prefLen-1-i)))
	}
	if suffix >= s {
		count++
	}

	return count
}