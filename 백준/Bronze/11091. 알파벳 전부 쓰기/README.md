# [Bronze II] 알파벳 전부 쓰기 - 11091 

[문제 링크](https://www.acmicpc.net/problem/11091) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 4월 1일 23:17:59

### 문제 설명

<p>A pangram is a phrase that includes at least one occurrence of each of the 26 letters, ‘a’. . .‘z’. You’re probably familiar with this one: “The quick brown fox jumps over the lazy dog.”</p>

<p>Your job is to recognize pangrams. For phrases that don’t contain every letter, report what letters are missing. We’ll say that a particular letter occurs in the phrase if it occurs as either upper case or lower case.</p>

### 입력 

 <p>Input starts with a line containing an integer 1 ≤ N ≤ 50. The next N lines are each a single phrase, possibly containing upper and lower case letters, spaces, decimal digits and punctuation characters ‘.’, ‘,’, ‘?’, ‘!’, ‘’’ and ‘"’. Each phrase contains at least one and no more than 100 characters.</p>

### 출력 

 <p>For each input phrase, output “pangram” if it qualifies as a pangram. Otherwise, output the word “missing” followed by a space and then the list of letters that didn’t occur in the phrase. The list of missing letters should be reported in lower case and should be sorted alphabetically.</p>

