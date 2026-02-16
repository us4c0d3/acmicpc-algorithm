# [Gold II] 모자 게임 - 21874 

[문제 링크](https://www.acmicpc.net/problem/21874) 

### 성능 요약

메모리: 47808 KB, 시간: 504 ms

### 분류

수학, 애드 혹

### 제출 일자

2026년 2월 12일 23:31:51

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/49ef4c39-5833-4ed7-8e40-8a883161e659/-/preview/"></p>

<p>CS-House에서는 매주 목요일에 연세대학교 컴퓨터과학과에 대한 여러 이야기를 팟캐스트 형식으로 다룬다. 2021년 3월 18일에 진행한 CS-House에서는 ICPC World Final에 진출한 윤인섭 선배가 게스트로 나와서 알고리즘 및 Competitive Programming에 대해서 이야기를 했다. 이야기 도중에 시청자들과 함께 재미있는 문제들을 풀어보는 시간을 가졌는데, 그 문제 중 하나를 변형해서 연세대학교 신입생 프로그래밍 경진대회에 내기로 했다. 다음과 같은 문제를 생각해보자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6d1c64a8-c896-46d6-8d2d-300ed8efa697/-/preview/"></p>

<p>그림과 같이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명의 사람이 앞을 보고 일렬로 서있다. 각 사람은 맨 뒷사람을 제외하고 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>63</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$63$</span></mjx-container> 이하의 정수가 적힌 모자를 쓰고 있다.</p>

<p style="text-align: center;"><img alt="" src=""></p>

<p>각 사람은 자신보다 앞에 있는 사람의 모자에 적힌 수를 모두 볼 수 있지만, 자신을 포함해서 뒤에 있는 사람의 모자에 적힌 수는 볼 수 없다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/16cbd0ee-12c7-439e-97e3-40f48af48263/-/preview/"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6b3f821c-cf4f-40e1-8619-aa06ca586aa1/-/preview/"></p>

<p>게임이 시작되면 맨 뒷 사람부터 순서대로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>63</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$63$</span></mjx-container> 이하의 정수 중 하나를 말한다.</p>

<p>게임을 시작하기 전 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명의 사람들이 모여 작전을 세우려고 한다. 자신이 말한 수와 자신의 모자에 적힌 수가 동일한 사람이 최대한 많아지도록 작전을 세워보자.</p>

<div class="headline">
<h2>구현</h2>
</div>

<p>이 문제를 풀기 위해서는 hat.cpp 파일을 제출해야 한다. hat.cpp 파일에 포함되어야 하는 함수는 다음과 같다..</p>

<pre>void init(int N);</pre>

<ul>
	<li>프로그램이 실행된 직후, 한 번만 호출된다. <code>N</code>은 일렬로 서있는 사람의 수를 의미한다.</li>
</ul>

<pre>int call(vector<int> F, vector<int> B, int num);</pre>

<ul>
	<li>앞에서부터 <code>(num+1)</code>번째에 서있는 사람이 말해야 하는 수를 <code>return</code>한다. <code>num</code>은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container> 이하의 정수다.</li>
	<li><code>F</code>는 앞에 있는 사람들이 쓴 모자의 수를 저장한 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 정수 배열이다. <code>F[i]</code>에는 <code>i+1</code>번째 사람이 쓴 모자의 수가 저장되어 있다. 만약 <code>num+1</code>번째 사람이 <code>i+1</code>번째 사람이 쓴 모자의 수를 볼 수 없다면 해당 배열 값은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>이다.</li>
	<li><code>B</code>는 뒤에 있는 사람들이 말한 수를 저장한 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 정수 배열이다. <code>B[i]</code>에는 <code>i+1</code>번째 사람이 말한 수가 저장되어 있다. 만약 <code>num+1</code>번째 사람이 말하기 전에 <code>i+1</code>번째 사람이 말하는 차례가 오지 않았다면 해당 배열 값은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>이다.</li>
	<li>각 게임마다 <code>call</code>은 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>번 호출된다. <code>call</code>이 호출될 때 마다 <code>num</code>에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container>부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>까지 수가 순서대로 들어간다.</li>
</ul>

<p>총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>번의 모자 게임이 동시에 진행되며, 각 게임별로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container>명이 자신이 쓴 모자에 적힌 수와 동일한 수를 말해야 <strong><span class="result-ac">맞았습니다!!</span></strong>를 받을 수 있다. Grader가 실행 도중 <span class="result-wa">틀렸습니다</span>라고 판정한 경우, 그 즉시 프로그램이 종료된다.</p>

### 입력 

 Empty

### 출력 

 Empty

