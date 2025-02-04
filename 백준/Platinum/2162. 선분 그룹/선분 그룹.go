package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

type Line struct {
	x1 int64
	y1 int64
	x2 int64
	y2 int64
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func ccw(x1, y1, x2, y2, x3, y3 int64) int64 {
	x := (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	} else {
		return 0
	}
}

func isIntersect(i, j int64, lines []Line) bool {
	ccw1 := ccw(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, lines[j].x1, lines[j].y1)
	ccw2 := ccw(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, lines[j].x2, lines[j].y2)
	ccw3 := ccw(lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2, lines[i].x1, lines[i].y1)
	ccw4 := ccw(lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2, lines[i].x2, lines[i].y2)

	if ccw1*ccw2 < 0 && ccw3*ccw4 < 0 {
		return true
	}
	if ccw1 == 0 &&
		lines[j].x1 >= min(lines[i].x1, lines[i].x2) && lines[j].x1 <= max(lines[i].x1, lines[i].x2) &&
		lines[j].y1 >= min(lines[i].y1, lines[i].y2) && lines[j].y1 <= max(lines[i].y1, lines[i].y2) {
		return true
	}
	if ccw2 == 0 &&
		lines[j].x2 >= min(lines[i].x1, lines[i].x2) && lines[j].x2 <= max(lines[i].x1, lines[i].x2) &&
		lines[j].y2 >= min(lines[i].y1, lines[i].y2) && lines[j].y2 <= max(lines[i].y1, lines[i].y2) {
		return true
	}
	if ccw3 == 0 &&
		lines[i].x1 >= min(lines[j].x1, lines[j].x2) && lines[i].x1 <= max(lines[j].x1, lines[j].x2) &&
		lines[i].y1 >= min(lines[j].y1, lines[j].y2) && lines[i].y1 <= max(lines[j].y1, lines[j].y2) {
		return true
	}
	if ccw4 == 0 &&
		lines[i].x2 >= min(lines[j].x1, lines[j].x2) && lines[i].x2 <= max(lines[j].x1, lines[j].x2) &&
		lines[i].y2 >= min(lines[j].y1, lines[j].y2) && lines[i].y2 <= max(lines[j].y1, lines[j].y2) {
		return true
	}

	return false
}

func getRoot(x int64, parent []int64) int64 {
	if parent[x] == x {
		return x
	}
	parent[x] = getRoot(parent[x], parent)
	return parent[x]
}

func merge(u, v int64, parent, componentSizes []int64) {
	uRoot := getRoot(u, parent)
	vRoot := getRoot(v, parent)

	if uRoot == vRoot {
		return
	}

	if uRoot < vRoot {
		componentSizes[uRoot] += componentSizes[vRoot]
		parent[vRoot] = uRoot
	} else {
		componentSizes[vRoot] += componentSizes[uRoot]
		parent[uRoot] = vRoot
	}
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int64
	fmt.Fscan(reader, &n)
	var x1, y1, x2, y2 int64
	lines := make([]Line, n)
	parent := make([]int64, n)
	componentSizes := make([]int64, n)

	for i := int64(0); i < n; i++ {
		fmt.Fscan(reader, &x1, &y1, &x2, &y2)
		lines[i] = Line{x1, y1, x2, y2}
		parent[i] = i
		componentSizes[i] = 1
	}

	for i := int64(0); i < n; i++ {
		for j := i + 1; j < n; j++ {
			if isIntersect(i, j, lines) {
				merge(i, j, parent, componentSizes)
			}
		}
	}

	count := int64(0)
	maxSize := int64(0)
	for i := int64(0); i < n; i++ {
		if parent[i] == i {
			count++
			if componentSizes[i] > maxSize {
				maxSize = componentSizes[i]
			}
		}
	}

	fmt.Fprintln(writer, count)
	fmt.Fprintln(writer, maxSize)
}