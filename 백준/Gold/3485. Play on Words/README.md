# [Gold III] Play on Words - 3485 

[문제 링크](https://www.acmicpc.net/problem/3485) 

### 성능 요약

메모리: 2024 KB, 시간: 200 ms

### 분류

자료 구조, 분리 집합, 오일러 경로, 그래프 이론

### 제출 일자

2024년 10월 15일 20:53:35

### 문제 설명

<p>Some of the secret doors contain a very interesting word puzzle. The team of archaeologists has to solve it to open that doors. Because there is no other way to open the doors, the puzzle is very important for us.</p>

<p>There is a large number of magnetic plates on every door. Every plate has one word written on it. The plates must be arranged into a sequence in such a way that every word begins with the same letter as the previous word ends. For example, the word "ac<u>m</u>" can be followed by the word "<u>m</u>otorola". Your task is to write a computer program that will read the list of words and determine whether it is possible to arrange all of the plates in a sequence (according to the given rule) and consequently to open the door.</p>

### 입력 

 <p>The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing a single integer number N that indicates the number of plates (1 <= N <= 100000). Then exactly Nlines follow, each containing a single word. Each word contains at least two and at most 1000 lowercase characters, that means only letters 'a' through 'z' will appear in the word. The same word may appear several times in the list.</p>

### 출력 

 <p>Your program has to determine whether it is possible to arrange all the plates in a sequence such that the first letter of each word is equal to the last letter of the previous word. All the plates from the list must be used, each exactly once. The words mentioned several times must be used that number of times.</p>

<p>If there exists such an ordering of plates, your program should print the sentence "Ordering is possible.". Otherwise, output the sentence "The door cannot be opened.".</p>

