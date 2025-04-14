# [Gold III] 페스트리 - 5625 

[문제 링크](https://www.acmicpc.net/problem/5625) 

### 성능 요약

메모리: 17652 KB, 시간: 88 ms

### 분류

누적 합

### 제출 일자

2025년 4월 14일 09:48:33

### 문제 설명

<p>Baker Crumble has just baked N triangular burek pastries. Each pastry can be represented in the Cartesian coordinate system as a triangle with vertices in integer coordinate points.</p>

<p>The baker's mischievous son Joey has just taken a large knife and started to cut the pastries. Each cut that Joey makes corresponds to a horizontal (y = c) or vertical (x = c) line in the coordinate system. Help the baker assess the damage caused by Joey's pastry cutting. Your task is to determine, for each Joey's cut, how many pastries are affected (such that both the left and right parts of the cut pastry have areas greater than zero).</p>

### 입력 

 <p>The first line of input contains the positive integer N (2 ≤ N ≤ 100 000), the number of burek pastries.</p>

<p>Each of the following N lines contains six nonnegative integers smaller than 10<sup>6</sup>. These numbers are, in order, the coordinates (x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>), (x<sub>3</sub>, y<sub>3</sub>) of the three pastry-triangle vertices. The three vertices will not all be on the same line. The pastries can touch as well as overlap.</p>

<p>The following line contains the positive integer M (2 ≤ M ≤ 100 000), the number of cuts.</p>

<p>Each of the following M lines contains a single cut line equation: “x = c” or “y = c” (note the spaces around the equals sign), where c is a nonnegative integer smaller than 10<sup>6</sup>.</p>

### 출력 

 <p>For each cut, output a line containing the required number of cut pastries.</p>

<p> </p>

