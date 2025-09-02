package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

const INF int = 1000000000

var reader *bufio.Reader
var writer *bufio.Writer
var dx = []int{-1, 1, 0, 0}
var dy = []int{0, 0, -1, 1}

type Item struct {
	x    int
	y    int
	time int
}

type Heap []Item

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i].time < h[j].time }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Heap) Push(x any) {
	*h = append(*h, x.(Item))
}

func (h *Heap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	var tg, tb, x, b int
	fmt.Fscan(reader, &n, &m, &tg, &tb, &x, &b)

	mat := make([][]byte, n)
	dist := make([][]int, n)
	for i := 0; i < n; i++ {
		mat[i] = make([]byte, m)
		dist[i] = make([]int, m)
		var s string
		fmt.Fscan(reader, &s)
		for j := 0; j < m; j++ {
			mat[i][j] = s[j]
			dist[i][j] = INF
		}
	}

	pq := &Heap{}
	heap.Init(pq)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == '*' {
				heap.Push(pq, Item{x: i, y: j, time: 0})
				dist[i][j] = 0
			}
		}
	}

	for pq.Len() > 0 {
		curr := heap.Pop(pq).(Item)

		if curr.time > dist[curr.x][curr.y] {
			continue
		}

		if curr.time > tg {
			continue
		}

		for i := 0; i < 4; i++ {
			nx := curr.x + dx[i]
			ny := curr.y + dy[i]

			if nx < 0 || ny < 0 || nx >= n || ny >= m {
				continue
			}

			var nextTime int
			if mat[nx][ny] == '#' {
				nextTime = curr.time + tb + 1
			} else {
				nextTime = curr.time + 1
			}

			if dist[nx][ny] == INF || nextTime < dist[nx][ny] {
				dist[nx][ny] = nextTime
				heap.Push(pq, Item{x: nx, y: ny, time: nextTime})
			}
		}
	}

	flag := false
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if dist[i][j] > tg || dist[i][j] == INF {
				fmt.Fprintf(writer, "%d %d\n", i+1, j+1)
				flag = true
			}
		}
	}

	if !flag {
		fmt.Fprintln(writer, "-1")
	}

}
