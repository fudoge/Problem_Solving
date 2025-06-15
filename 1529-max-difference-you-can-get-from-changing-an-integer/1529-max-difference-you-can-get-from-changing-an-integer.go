func maxDiff(num int) int {
    numstr := strconv.Itoa(num) 
    mx := []byte(numstr)
    mn := []byte(numstr)

    maxReplace := byte('9')
    for i := 0; i < len(numstr); i++ {
        if numstr[i] != '9' {
            maxReplace = byte(numstr[i])
            break
        }
    }
    for i := 0; i < len(mx); i++ {
        if mx[i] == maxReplace {
            mx[i] = '9'
        }
    }

    minReplace := byte(0)
    if numstr[0] != '1' {
        minReplace = numstr[0]
        for i := 0; i < len(mn); i++ {
            if mn[i] == minReplace {
                mn[i] = '1'
            }
        }
    } else {
        for i := 1; i < len(numstr); i++ {
            if numstr[i] != '0' && numstr[i] != '1' {
                minReplace = numstr[i]
                break
            }
        }
        if minReplace != 0 {
            for i := 1; i < len(mn); i++ {
                if mn[i] == minReplace {
                    mn[i] = '0'
                }
            }
        }
    }

    maxNum, _ := strconv.Atoi(string(mx))
    minNum, _ := strconv.Atoi(string(mn))
    return maxNum - minNum
}