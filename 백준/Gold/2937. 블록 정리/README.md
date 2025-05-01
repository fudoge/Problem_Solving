# [Gold IV] 블록 정리 - 2937 

[문제 링크](https://www.acmicpc.net/problem/2937) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘, 누적 합

### 제출 일자

2025년 5월 1일 13:28:29

### 문제 설명

<p>In the nearby kindergarten they recently made up an attractive game of strength and agility that kids love. </p>

<p>The surface for the game is a large flat area divided into N×N squares. </p>

<p>The children lay large spongy cues onto the surface. The sides of the cubes are the same length as the sides of the squares. When a cube is put on the surface, its sides are aligned with some square. A cube may be put on another cube too. </p>

<p>Kids enjoy building forts and hiding them, but they always leave behind a huge mess. Because of this, prior to closing the kindergarten, the teachers rearrange all the cubes so that they occupy a rectangle on the surface, with exactly one cube on every square in the rectangle. </p>

<p>In one moving, a cube is taken off the top of a square to the top of any other square. </p>

<p>Write a program that, given the state of the surface, calculates the smallest number of moves needed to arrange all cubes into a rectangle. </p>

### 입력 

 <p>The first line contains the integers N and M (1 ≤ N ≤ 100, 1 ≤ M ≤ N<sup>2</sup>), the dimensions of the surface and the number of cubes currently on the surface. </p>

<p>Each of the following M lines contains two integers R and C (1 ≤ R, C ≤ N), the coordinates of the square that contains the cube. </p>

### 출력 

 <p>Output the smallest number of moves. A solution will always exist. </p>

