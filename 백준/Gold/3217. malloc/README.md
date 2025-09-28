# [Gold I] malloc - 3217 

[문제 링크](https://www.acmicpc.net/problem/3217) 

### 성능 요약

메모리: 2168 KB, 시간: 44 ms

### 분류

구현, 자료 구조, 연결 리스트

### 제출 일자

2025년 9월 28일 14:52:23

### 문제 설명

<p>Write a program that will simulate the execution of memory allocation commands. </p>

<p>Memory is a sequence of 100,000 continuous memory locations, numbered from 1 to 100,000. </p>

<p>In the beginning, all locations are free. </p>

<p>Commands that can occur are: </p>

<p>1.) var=malloc(size); </p>

<p>This function finds the first size (100 ≤ size ≤ 100,000) continuous free locations, and allocates them. Return value of this function is either the address of the first allocated location or 0 if there is no such sequence. </p>

<p>2.) free(var); </p>

<p>This function frees all the memory locations assigned to the variable var (by previous use of malloc) and sets the value of var to 0. </p>

<p>If the value of variable var is already 0, nothing happens. </p>

<p>3.) print(var); </p>

<p>This function prints the value of variable var. </p>

<p>Every command line ends with a semicolon (';'). </p>

<p>Variables are strings of exactly four small letters of the english alphabet ('a'...'z'). </p>

<p>Number of different variables will be less than or equal to 1000. </p>

<p>All variables are set to 0 in the beginning. </p>

### 입력 

 <p>In the first line there is an integer N, 1 ≤ N ≤ 100,000, number of commands (at least one of the commands will be 'print'). </p>

<p>In each of the following N lines there is one command, in order of their execution. </p>

### 출력 

 <p>Write the results of all 'print' commands, in order of their execution, each one in separate line. </p>

<p> </p>

