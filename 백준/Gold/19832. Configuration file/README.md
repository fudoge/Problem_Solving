# [Gold IV] Configuration file - 19832 

[문제 링크](https://www.acmicpc.net/problem/19832) 

### 성능 요약

메모리: 10660 KB, 시간: 60 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 파싱, 시뮬레이션, 스택, 문자열

### 제출 일자

2025년 3월 1일 02:37:39

### 문제 설명

<p>Vadim develops a parser for configuration files of his project. A configuration file consists of blocks delimited with braces: "<code>{</code>" marks the beginning of the block, and "}" marks the end of the block. Blocks can be nested. One block can contains several other blocks.</p>

<p>There are variables in the configuration file. Each variable has a name that consists of at most ten lowercase English letters. Each variable has an integer value, initially all variables are set to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>. </p>

<p>New values can be assigned to variables. Assigning a constant value to a variable is specified as "<code><variable>=<number></code>", here <code><variable></code> is the variable's name, and <code><number></code> is an integer, its absolute value doesn't exceed <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9$</span></mjx-container>. The parser reads the file line after line. As it reads the assignment operation, it assigns the new value to the variable. This value is used until the end of the current block, after that the previous value is restored. If the current block has some nested blocks following the assignment, the new value of the variable is used inside those blocks.</p>

<p>A variable can also be assigned the value of another variable. Such operation is specified as "<code><variable1>=<variable2></code>". When the parser reads such line, it assigns the current value of <code>variable2</code> to <code>variable1</code>. Similarly to the case of a constant value assignment, the new value is used until the end of the current block. After the end of the current block, the value that the variable had at the beginning of the block is restored.</p>

<p>For debugging purpose Vadim wants to print all values that are assigned when processing lines of the form "<code><variable1>=<variable2></code>". Help him to debug the parser.</p>

### 입력 

 <p>Input data contains at least <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> and at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^5$</span></mjx-container> lines. Each line has one of four types:</p>

<ul>
	<li><code>{</code> --- beginning of the block;</li>
	<li>} --- end of block;</li>
	<li><code><variable>=<number></code> --- assigning a constant value to a variable;</li>
	<li><code><variable1>=<variable2></code> --- assigning one variable to another, here <code><variable1></code> and <code><variable2></code> can be the same.</li>
</ul>

<p>It is guaranteed that the input is correct and corresponds to the statement. Input doesn't contain spaces.</p>

### 출력 

 <p>For each line that has the form "<code><variable1>=<variable2></code>" print the value that is assigned.</p>

