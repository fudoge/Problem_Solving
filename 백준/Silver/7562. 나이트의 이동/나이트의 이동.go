package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer
var knightMoves = [][]int32{
	{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
	{1, -2}, {1, 2}, {2, -1}, {2, 1},
}

type Pair struct {
	First  int32
	Second int32
}

type Queue struct {
	data []Pair
}

func (q *Queue) Empty() bool {
	return len(q.data) == 0
}

func (q *Queue) Push(p Pair) {
	q.data = append(q.data, p)
}

func (q *Queue) Pop() (Pair, bool) {
	if q.Empty() {
		return Pair{}, false
	}
	front := q.data[0]
	q.data = q.data[1:]
	return front, true
}

func solve() {
	var l, sr, sc, er, ec int32
	fmt.Fscan(reader, &l)
	fmt.Fscan(reader, &sr, &sc)
	fmt.Fscan(reader, &er, &ec)

	visited := make([][]bool, l)
	for i := int32(0); i < l; i++ {
		visited[i] = make([]bool, l)
	}

	q := Queue{}
	q.Push(Pair{sr, sc})
	visited[sr][sc] = true
	depth := int32(0)

	for !q.Empty() {
		qsize := len(q.data)
		for i := 0; i < qsize; i++ {
			p, _ := q.Pop()
			x := p.First
			y := p.Second

			if x == er && y == ec {
				fmt.Fprintln(writer, depth)
				return
			}

			for _, mov := range knightMoves {
				nx := x + mov[0]
				ny := y + mov[1]

				if nx < 0 || ny < 0 || nx >= l || ny >= l || visited[nx][ny] {
					continue
				}

				visited[nx][ny] = true
				q.Push(Pair{nx, ny})
			}
		}
		depth++
	}
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int32
	fmt.Fscan(reader, &t)

	for t > 0 {
		solve()
		t--
	}
}