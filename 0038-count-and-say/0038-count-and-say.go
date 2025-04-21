func countAndSay(n int) string {
	str := "1"

	for i := 2; i <= n; i++ {
		newStr := ""
		l := 0
		for r := 0; r < len(str); {
			for r < len(str) && str[l] == str[r] {
				r++
			}
			newStr += string(byte(r - l + '0'))
			newStr += string(str[l])
			l = r
		}
		str = newStr
	}
	return str
}
