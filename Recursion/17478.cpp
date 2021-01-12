<<<<<<< HEAD
//https://www.acmicpc.net/problem/17478
=======
//noj.am/17478
>>>>>>> 326649ecc6bd774a4243e0f0d7142a197e83865d
//Recursion
#include <stdio.h>

int n;

void dash(int x) {
	if (x <= 0) return;
	dash(x-1);
	printf("____");
}

void chat(int x) {
	if (x <= 0) return;
	dash(n-x);
	puts("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
	dash(n-x);
	puts("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
	dash(n-x);
	puts("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""); 
	dash(n-x+1);
	puts("\"재귀함수가 뭔가요?\""); 
	chat(x-1);
	if (x == 1) {
		dash(n-x+1);
		puts("\"재귀함수는 자기 자신을 호출하는 함수라네\"");
		dash(n-x+1);
		puts("라고 답변하였지.");
	} 
	dash(n-x);
	puts("라고 답변하였지.");
}

int main() {
	scanf("%d", &n);
	puts("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
	puts("\"재귀함수가 뭔가요?\""); 
	chat(n);
	return 0;
}