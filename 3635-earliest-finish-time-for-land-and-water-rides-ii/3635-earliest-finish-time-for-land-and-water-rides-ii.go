// O(n log n) + O(m log m)

type Item struct {
    startTime      int
    duration       int
    idealEndTime   int
}

func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    n := len(landStartTime)         
    m := len(waterStartTime)         

    // Sort each rides in starting time order
    landRide := make([]Item, n)
    waterRide := make([]Item, m)
    for i := 0; i < n; i++ {
        landRide[i] = Item{
            startTime:    landStartTime[i],
            duration:     landDuration[i],
            idealEndTime: landStartTime[i] + landDuration[i],
        }
    }
    for i := 0; i < m; i++ {
        waterRide[i] = Item{
            startTime:    waterStartTime[i],
            duration:     waterDuration[i],
            idealEndTime: waterStartTime[i] + waterDuration[i],
        }
    }
    slices.SortFunc(landRide, func(a, b Item) int {
        return cmp.Compare(a.startTime, b.startTime)
    })
    slices.SortFunc(waterRide, func(a, b Item) int {
        return cmp.Compare(a.startTime, b.startTime)
    })

    // Suffix Best Endtime
    bestLandFinish := make([]int, n)
    bestLandFinish[n-1] = landRide[n-1].idealEndTime
    bestWaterFinish := make([]int, m)
    bestWaterFinish[m-1] = waterRide[m-1].idealEndTime
    for i := n-2; i >= 0; i--  {
        bestLandFinish[i] = min(bestLandFinish[i+1], landRide[i].idealEndTime)
    }
    for i := m-2; i >= 0; i--  {
        bestWaterFinish[i] = min(bestWaterFinish[i+1], waterRide[i].idealEndTime)
    }

    // Prefix Best Duration
    minLandDuration := make([]int, n)
    minLandDuration[0] = landRide[0].duration
    minWaterDuration := make([]int, m)
    minWaterDuration[0] = waterRide[0].duration
    for i := 1; i < n; i++ {
        minLandDuration[i] = min(minLandDuration[i-1], landRide[i].duration)
    }
    for i := 1; i < m; i++ {
        minWaterDuration[i] = min(minWaterDuration[i-1], waterRide[i].duration)
    }

    ans := math.MaxInt
    // Land -> Water
    for i := 0; i < n; i++ {
        firstEnd := landRide[i].idealEndTime
        // Binary Search
        nextAvailableIdx := sort.Search(len(waterRide), func(j int) bool {
            return waterRide[j].startTime >= firstEnd
        })
        // Consider Prefix Best
        if nextAvailableIdx > 0 {
            ans = min(ans, firstEnd + minWaterDuration[nextAvailableIdx-1])
        }
        // Consider Suffix Best
        if nextAvailableIdx < m {
            ans = min(ans, bestWaterFinish[nextAvailableIdx])
        }
    }

    // Reversed Order(Water -> Land)
    for i := 0; i < m; i++ {
        firstEnd := waterRide[i].idealEndTime
        nextAvailableIdx := sort.Search(len(landRide), func(j int) bool {
            return landRide[j].startTime >= firstEnd
        })
        if nextAvailableIdx > 0 {
            ans = min(ans, firstEnd + minLandDuration[nextAvailableIdx-1])
        }
        if nextAvailableIdx < n {
            ans = min(ans, bestLandFinish[nextAvailableIdx])
        }
    }

    return ans
}