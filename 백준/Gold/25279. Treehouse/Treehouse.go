package main

import (
	"bufio"
	"fmt"
	"os"
)

type Point struct {
	x int32
	y int32
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int32
	fmt.Fscan(reader, &n)

	points := make([]Point, n)
	pointMap := make(map[Point]bool)

	for i := int32(0); i < n; i++ {
		var x, y int32
		fmt.Fscan(reader, &x, &y)

		points[i] = Point{x, y}
		pointMap[points[i]] = true
	}

	ans := int32(0)
	for i := int32(0); i < n; i++ {
		for j := i + 1; j < n; j++ {
			x1 := points[i].x
			y1 := points[i].y
			x2 := points[j].x
			y2 := points[j].y

			dx := x2 - x1
			dy := y2 - y1

			p3 := Point{x1 - dy, y1 + dx}
			p4 := Point{x2 - dy, y2 + dx}

			if _, ok1 := pointMap[p3]; ok1 {
				if _, ok2 := pointMap[p4]; ok2 {
					ans++
				}
			}

			p3.x = x1 + dy
			p3.y = y1 - dx
			p4.x = x2 + dy
			p4.y = y2 - dx

			if _, ok1 := pointMap[p3]; ok1 {
				if _, ok2 := pointMap[p4]; ok2 {
					ans++
				}
			}
		}
	}

	fmt.Fprintln(writer, ans/4)
}