var dx []int = []int{-1, 1, 0, 0}
var dy []int = []int{0, 0, -1, 1}

type Item struct {
    dist int
    turn int
    x int
    y int
}

type PriorityQueue []*Item
func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {return pq[i].dist < pq[j].dist}
func (pq PriorityQueue) Swap(i, j int) {pq[i], pq[j] = pq[j], pq[i]}

func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(*Item)
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    *pq = old[0:n-1]
    return item
}

func minTimeToReach(moveTime [][]int) int {
    n, m := len(moveTime), len(moveTime[0])
    dist := make([][]int, n) 
    for i := 0; i < n; i++ {
        dist[i] = make([]int, m)
        for j := 0; j < m; j++ {
            dist[i][j] = int(^uint(0) >> 1)
        }
    }

    pq := make(PriorityQueue, 0)
    heap.Init(&pq)

    heap.Push(&pq, &Item{dist:0, turn:0, x:0, y:0})
    for pq.Len() > 0 {
        currItem := heap.Pop(&pq).(*Item)
        curDist, turn, x, y := currItem.dist, currItem.turn, currItem.x, currItem.y

        if curDist > dist[x][y] {
            continue
        }

        for i := 0; i < 4; i++ {
            nx := x + dx[i]
            ny := y + dy[i]

            if nx < 0 || ny < 0 || nx >= n || ny >= m {
                continue
            }
            nextDist := max(curDist, moveTime[nx][ny]) + (turn%2) + 1;
            if dist[nx][ny] > nextDist {
                dist[nx][ny] = nextDist
                heap.Push(&pq, &Item{dist:nextDist, turn:turn+1, x:nx, y:ny})
            }
        }
    }

    return dist[n-1][m-1]
}