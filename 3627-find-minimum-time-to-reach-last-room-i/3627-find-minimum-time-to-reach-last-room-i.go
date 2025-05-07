type Item struct {
	time, x, y int
}

type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].time < pq[j].time
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[:n-1]
	return item
}

func minTimeToReach(moveTime [][]int) int {
	n := len(moveTime)
	m := len(moveTime[0])
	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, -1, 1}

	dist := make([][]int, n)
	for i := range dist {
		dist[i] = make([]int, m)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt
		}
	}

	pq := &PriorityQueue{}
	heap.Init(pq)

	dist[0][0] = moveTime[0][0]
	heap.Push(pq, Item{0, 0, 0})

	for pq.Len() > 0 {
		cur := heap.Pop(pq).(Item)
		curTime, x, y := cur.time, cur.x, cur.y

		for i := 0; i < 4; i++ {
			nx := x + dx[i]
			ny := y + dy[i]

			if nx < 0 || ny < 0 || nx >= n || ny >= m {
				continue
			}

			nextTime := max(moveTime[nx][ny], curTime) + 1
			if dist[nx][ny] > nextTime {
				dist[nx][ny] = nextTime
				heap.Push(pq, Item{nextTime, nx, ny})
			}
		}
	}

	return dist[n-1][m-1]
}