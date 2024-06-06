func minRemoveToMakeValid(s string) string {
	var temp strings.Builder
	var opening int

	for _, ch := range s {
		if ch == '(' {
			opening++
		} else if ch == ')' {
			if opening > 0 {
				opening--
			} else {
				continue
			}
		}
		temp.WriteRune(ch)
	}
	s = ""
	opening = 0

	for i := temp.Len() - 1; i >= 0; i-- {
		ch := temp.String()[i]
		if ch == ')' {
			opening++
		} else if ch == '(' {
			if opening > 0 {
				opening--
			} else {
				continue
			}
		}

		s += string(ch)
	}

	return reverseString(s)
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}