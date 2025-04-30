# [Gold IV] 학회원 - 3865 

[문제 링크](https://www.acmicpc.net/problem/3865) 

### 성능 요약

메모리: 2300 KB, 시간: 4 ms

### 분류

너비 우선 탐색, 자료 구조, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 파싱, 문자열

### 제출 일자

2025년 4월 30일 09:13:14

### 문제 설명

<p>Peter is a senior manager of Agile Change Management (ACM) Inc., where each employee is a member of one or more task groups. Since ACM is agile, task groups are often reorganized and their members frequently change, so membership management is his constant headache.</p>

<p>Peter updates the membership information whenever any changes occur: for instance, the following line written by him means that Carol and Alice are the members of the Design Group.</p>

<pre>design:carol,alice.</pre>

<p>The name preceding the colon is the group name and the names following it specify its members.</p>

<p>A smaller task group may be included in a larger one. So, a group name can appear as a member of another group, for instance, as follows.</p>

<pre>development:alice,bob,design,eve.</pre>

<p>Simply unfolding the design above gives the following membership speciﬁcation, which is equivalent to the original.</p>

<pre>development:alice,bob,carol,alice,eve.</pre>

<p>In this case, however, alice occurs twice. After removing one of the duplicates, we have the following more concise speciﬁcation.</p>

<pre>development:alice,bob,carol,eve.</pre>

<p>Your mission in this problem is to write a program that, given group speciﬁcations, identifies group members.</p>

<p>Note that Peter’s speciﬁcations can include deeply nested groups. In the following, for instance, the group one contains a single member dave.</p>

<pre>one:another.
another:yetanother.
yetanother:dave.</pre>

### 입력 

 <p>The input is a sequence of datasets, each being in the following format.</p>

<pre>n
group<sub>1</sub>:member<sub>1,1</sub>,...,member<sub>1,m1.</sub>
.
.
.
group<sub>i</sub>:member<sub>i,1</sub>,...,member<sub>i,mi.</sub>
.
.
.
group<sub>n</sub>:member<sub>n,1</sub>,...,member<sub>n,mn</sub>.</pre>

<p>The first line contains n, which represents the number of groups and is a positive integer no more than 100. Each of the following n lines contains the membership information of a group: group<sub>i</sub> (1 ≤ i ≤ n) is the name of the i-th task group and is followed by a colon (:) and then the list of its m<sub>i</sub> members that are delimited by a comma (,) and terminated by a period (.).</p>

<p>Those group names are mutually diﬀerent. Each m<sub>i</sub> (1 ≤ i ≤ n) is between 1 and 10, inclusive. A member is another group name if it is one of group<sub>1</sub>, group<sub>2</sub>, . . . , or group<sub>n</sub>. Otherwise it is an employee name.</p>

<p>There are no circular (or recursive) definitions of group(s). You may assume that mi member names of a group are mutually diﬀerent.</p>

<p>Each group or employee name is a non-empty character string of length between 1 and 15, inclusive, and consists of lowercase letters.</p>

<p>The end of the input is indicated by a line containing a zero.</p>

### 출력 

 <p>For each dataset, output the number of employees included in the ﬁrst group of the dataset, that is group<sub>1</sub>, in a line. No extra characters should occur in the output.</p>

