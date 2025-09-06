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

type Item struct {
	Node int
	Dist int
}

type Edge struct {
	u   int
	v   int
	dir int
}

type Heap []Item

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i].Dist < h[j].Dist }
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

	var n, m, s, e int
	fmt.Fscan(reader, &n, &m, &s, &e)

	edges := make([]Edge, m)
	adj := make([][]int, n+1)
	dist := make([]int, n+1)
	prev := make([]int, n+1)
	nodeWeight := make([]int, n+1)
	for i := 0; i <= n; i++ {
		adj[i] = make([]int, 0)
		dist[i] = INF
		prev[i] = -1
		nodeWeight[i] = 0
	}
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		edges[i].u = u
		edges[i].v = v
		edges[i].dir = -1

		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	pq := make(Heap, 0)
	heap.Init(&pq)
	dist[s] = 0

	heap.Push(&pq, Item{Node: s, Dist: 0})
	for pq.Len() > 0 {
		curr := heap.Pop(&pq).(Item)

		if curr.Dist > dist[curr.Node] {
			continue
		}

		for _, nextNode := range adj[curr.Node] {
			nextDist := curr.Dist + 1
			if nextDist < dist[nextNode] {
				dist[nextNode] = nextDist
				prev[nextNode] = curr.Node
				heap.Push(&pq, Item{Node: nextNode, Dist: nextDist})
			}
		}
	}

	if dist[e] == INF {
		fmt.Fprintln(writer, -1)
		return
	}

	trace := make([]int, 0)
	pos := e
	for prev[pos] != -1 {
		trace = append(trace, pos)
		pos = prev[pos]
	}
	trace = append(trace, pos)
	for i := 0; i < len(trace)/2; i++ {
		trace[i], trace[len(trace)-i-1] = trace[len(trace)-i-1], trace[i]
	}

	w := 1
	for i := 0; i < len(trace); i++ {
		nodeWeight[trace[i]] = w
		w++
	}

	for i := 0; i < m; i++ {
		if nodeWeight[edges[i].u] > nodeWeight[edges[i].v] {
			edges[i].dir = 1
		} else {
			edges[i].dir = 0
		}
		fmt.Fprintf(writer, "%d ", edges[i].dir)
	}

	fmt.Fprintln(writer)
}
