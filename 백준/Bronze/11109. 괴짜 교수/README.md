# [Bronze III] 괴짜 교수 - 11109 

[문제 링크](https://www.acmicpc.net/problem/11109) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

사칙연산, 수학

### 제출 일자

2025년 4월 1일 23:31:16

### 문제 설명

<p>Lasse is a nutty professor. He believes strongly that in order to make computer programs for the future, one should make them parallel. In order to convince the rest of the world that he is correct he wants to carry out an experiment. The experiment proceeds as follows: For a number of problems where a serial implementation is available, he estimates the number of times this program will be executed within the next year (when the program will probably be rewritten). He orders his slave, Magnus, to develop a parallel version of the program and measures the amount of time Magnus uses developing it. At the end, they measure the execution time of both the parallel and the serial version.</p>

<p>Based on the collected data, Lasse wants to know in which cases the overall number of man-hours spent on this program is minimized by parallelizing. Man-hours are spent developing the parallel version and waiting while programs execute.</p>

### 입력 

 <p>The input has t ≤ 1000 cases, where t is given by the first line of input. Each test case is given by a line with four integers d, n, s and p separated by a single space. d is the time spent developing the parallel version (0 ≤ d ≤ 1000000), and n is the expected number of times this program will be executed during the next year (0 ≤ n ≤ 100000). s and p are the running times of the serial and parallel version of the program respectively (0 ≤ s, p ≤ 1000).</p>

### 출력 

 <p>For each test case output ”parallelize” on a single line if it is beneficial to parallelize. If it is not beneficial to parallelize, the outputted line should be ”do not parallelize”. If the expected total time spent with the program is similar regardless of whether it is parallelized or not, the outputted line should be ”does not matter”.</p>

