type block struct {
    val int64
    cnt int64
}

type monoAgg struct {
    q     []block
    head  int
    sum   int64
    isMax bool
}

func (m *monoAgg) push(x int64) {
    cnt := int64(1)

    if m.isMax {
        for len(m.q) > m.head && m.q[len(m.q)-1].val <= x {
            last := m.q[len(m.q)-1]
            m.q = m.q[:len(m.q)-1]
            m.sum -= last.val * last.cnt
            cnt += last.cnt
        }
    } else {
        for len(m.q) > m.head && m.q[len(m.q)-1].val >= x {
            last := m.q[len(m.q)-1]
            m.q = m.q[:len(m.q)-1]
            m.sum -= last.val * last.cnt
            cnt += last.cnt
        }
    }

    m.q = append(m.q, block{x, cnt})
    m.sum += x * cnt
}

func (m *monoAgg) popStart() {
    m.sum -= m.q[m.head].val
    m.q[m.head].cnt--

    if m.q[m.head].cnt == 0 {
        m.head++
    }
}

func (m *monoAgg) front() int64 {
    return m.q[m.head].val
}

func countLess(nums []int, limit int64) (int64, int64) {
    if limit <= 0 {
        return 0, 0
    }

    maxAgg := monoAgg{isMax: true}
    minAgg := monoAgg{isMax: false}

    left := 0
    var count int64
    var sum int64

    for right, num := range nums {
        x := int64(num)

        maxAgg.push(x)
        minAgg.push(x)

        for maxAgg.front()-minAgg.front() >= limit {
            maxAgg.popStart()
            minAgg.popStart()
            left++
        }

        count += int64(right - left + 1)
        sum += maxAgg.sum - minAgg.sum
    }

    return count, sum
}

func maxTotalValue(nums []int, k int) int64 {
    n := len(nums)

    mn, mx := nums[0], nums[0]
    for _, x := range nums {
        if x < mn {
            mn = x
        }
        if x > mx {
            mx = x
        }
    }

    maxDiff := int64(mx) - int64(mn)
    totalCount := int64(n) * int64(n+1) / 2

    _, totalSum := countLess(nums, maxDiff+1)

    K := int64(k)

    lo, hi := int64(0), maxDiff

    for lo < hi {
        mid := (lo + hi + 1) / 2

        lessCount, _ := countLess(nums, mid)
        greaterOrEqualCount := totalCount - lessCount

        if greaterOrEqualCount >= K {
            lo = mid
        } else {
            hi = mid - 1
        }
    }

    threshold := lo

    lessCount, lessSum := countLess(nums, threshold+1)

    greaterCount := totalCount - lessCount
    greaterSum := totalSum - lessSum

    return greaterSum + (K-greaterCount)*threshold
}