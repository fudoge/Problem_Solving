# [Gold I] Explore space - 14616 

[문제 링크](https://www.acmicpc.net/problem/14616) 

### 성능 요약

메모리: 4372 KB, 시간: 264 ms

### 분류

기하학, 그리디 알고리즘, 정렬, 스위핑

### 제출 일자

2025년 6월 6일 12:16:15

### 문제 설명

<p dir="ltr">지금으로부터 멀지 않은 미래 항성 간 이동이 가능해진 인류는 새로운 보금자리를 찾기 위한 여정을 떠난다. 긴 시간 끝에 마지막 웜홀을 눈앞에 두고 있지만 웜홀 안에는 방사능 층이 가득해 그냥 이용할 경우 수많은 사람들이 피폭당할 수 있다.</p>

<p dir="ltr">다행히 인류에게는 방사능 층을 파괴할 수 있는 레이저를 가지고 있다. 레이저는 발사 위치로부터 반직선 형태로 발사되며 충돌하는 모든 방사능 층을 파괴할 수 있는 능력을 가지고 있다. 웜홀 안에 존재하는 방사능 층의 상태와 레이저의 발사 위치들이 주어졌을 때 레이저를 발사한 뒤 남은 방사능 층이 몇 개인지 시뮬레이션 하는 프로그램을 작성해보자.</p>

<p dir="ltr">편의상 레이저의 위치는 (0, 0)이라고 하자. 이때 방사능 층들의 위치는 2차원 좌표 평면상 제1사분면의 선분으로 표현할 수 있다. 레이저의 발사 위치는 (X,Y)로 나타낼 수 있으며 이는 (0, 0)에서 (X,Y)로 향하는 반직선 형태로 레이저를 발사함을 의미한다.</p>

<p dir="ltr">다음 그림은 한 방사능 층에 대해 레이저를 발사하는 서로 다른 두 경우를 보여준다.</p>

<p dir="ltr" style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14616/1.png" style="height:242px; width:435px"></p>

<p dir="ltr">그림 (a)는 (2, 4)를 향해 발사한 레이저가 방사능 층과 충돌해 방사능 층을 파괴하는 모습을 나타낸다. 그림 (b)는 (3, 2)를 향해 발사한 레이저가 방사능 층을 파괴하지 못하고 빗겨나가는 모습을 나타낸다.</p>

<p dir="ltr">발사된 레이저가 방사능 층 선분의 시작 혹은 끝을 정확히 지나도 방사능 층과 레이저가 충돌한다고 간주한다. 발사된 레이저의 두께는 정말 얇기 때문에 레이저의 두께를 고려해서 계산할 필요는 없다.</p>

### 입력 

 <p>첫 번째 줄에 웜홀 안에 존재하는 방사능 층의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에 걸쳐 i(1 ≤ i ≤ N)번째 방사능 층을 나타내는 선분의 양끝점 좌표가 주어진다. 다음 줄에는 레이저의 발사 횟수 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 M개의 줄에 걸쳐 j(1 ≤ j ≤ M)번째 레이저의 발사 위치가 주어진다. 입력으로 주어지는 모든 좌표의 크기는 1보다 크거나 같고 100,000보다 작거나 같다. 방사능 층을 나타내는 선분의 시작과 끝은 동일할 수 있다.</p>

### 출력 

 <p>첫 번째 줄에 모든 레이저를 발사한 뒤 웜홀 안에 존재하는 방사능 층의 개수를 출력한다</p>

