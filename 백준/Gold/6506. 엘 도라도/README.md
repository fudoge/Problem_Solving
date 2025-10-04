# [Gold V] 엘 도라도 - 6506 

[문제 링크](https://www.acmicpc.net/problem/6506) 

### 성능 요약

메모리: 2152 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 10월 4일 23:05:04

### 문제 설명

<p>Bruce Force has gone to Las Vegas, the El Dorado for gamblers. He is interested especially in one betting game, where a machine forms a sequence of n numbers by drawing random numbers. Each player should estimate beforehand, how many increasing subsequences of length k will exist in the sequence of numbers.</p>

<p>A subsequence of a sequence a<sub>1</sub>, ..., a<sub>n</sub> is defined as a<sub>i1</sub>, ..., a<sub>il</sub>, where 1 ≤ i<sub>1</sub> < i2 < ... < il ≤ n. The subsequence is increasing, if a<sub>ij-1</sub> < a<sub>ij</sub> for all 1 < j ≤ l.</p>

<p>Bruce doesn't trust the Casino to count the number of increasing subsequences of length k correctly. He has asked you if you can solve this problem for him.</p>

### 입력 

 <p>The input contains several test cases. The first line of each test case contains two numbers n and k (1 ≤ k ≤ n ≤ 100), where n is the length of the sequence drawn by the machine, and k is the desired length of the increasing subsequences. The following line contains n pairwise distinct integers a<sub>i</sub> (-10000 ≤ a<sub>i</sub> ≤ 10000 ), where ai is the ith number in the sequence drawn by the machine.</p>

<p>The last test case is followed by a line containing two zeros.</p>

### 출력 

 <p>For each test case, print one line with the number of increasing subsequences of length k that the input sequence contains. You may assume that the inputs are chosen in such a way that this number fits into a 64 bit signed integer (in C/C++, you may use the data type "long long", in Java the data type "long").</p>

