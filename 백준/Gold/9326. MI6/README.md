# [Gold III] MI6 - 9326 

[문제 링크](https://www.acmicpc.net/problem/9326) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학, 정수론, 소수 판정

### 제출 일자

2025년 6월 7일 18:09:44

### 문제 설명

<p>MI6 uses a Spy Identiﬁcation Code (SIC) to identify their spies. For example, J. B. has a SIC of 7. The SICs have been assigned to the spies in such a way that MI6 can easily refer to any group of spies by using a status code that is the product of all SICs of the spies in the group. More precisely, the SICs are chosen in such a way that each status code ≥ 2 refers to a unique group of spies, and for each group of spies there is a unique status code referring to it.</p>

<p>Write a program that, given a status code, returns the SICs of the spies that belong to the group corresponding to that status code.</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with an integer c (2 ≤ c ≤ 10<sup>9</sup>): the status code.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with a space-separated list of SICs for the status code, in increasing order</li>
</ul>

