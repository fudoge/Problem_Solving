func nextGreatestLetter(letters []byte, target byte) byte {
    ans := byte('|')

    for _, let := range letters {
        if let > target {
            ans = min(ans, let)
        }
    }

    if ans == '|' { return letters[0] }
    return ans
}