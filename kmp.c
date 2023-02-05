#include <stdio.h>
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100

int pmatch(char* string, char* pat);
void fail();
int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

int main() {
	int i, j;
	int begin = 0, m = 0, res = 0;

	for (i = 0; i < 20; i++) {
		failure[i] = -1;
	}

	printf("문자열을 입력하세요 : ");
	scanf("%s", string);
	printf("비교할 패턴을 입력하세요 : ");
	scanf("%s", pat);

	fail();

	res = pmatch(string, pat);


	printf("\npat의 위치 정보 값\n");
	for (i = 0; i < strlen(pat); i++) {
		printf("failure[%d] = %3d ", i, failure[i]);
		if ((i + 1) % 5 == 0) printf("\n");
	}

	if (res != -1) {
		printf("\n문자열 %d 번째부터 패턴이 시작됨..", res);
	}
	else {
		printf("\n문자열을 찾을 수 없음..");
	}

	return 0;
}

void fail() {
	/* 실패함수 */
	int i, j, status;

	for (i = 0, j = 1, status = -1; j < strlen(pat); ++j) {
		if (pat[i] == pat[j]) {
			i++;
			failure[j] = ++status;
		}
		else {
			i = 0;
			failure[j] = -1;
			status = -1;
		}
	}
}

int pmatch(char* string, char* pat) {
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	while (i < lens && j < lenp) {
		if (string[i] == pat[j]) {
			i++;
			j++;
		}
		else if (j == 0) {
			i++;
		}
		else {
			j = failure[j - 1] + 1;
		}
	}

	return ((j == lenp) ? (i - lenp) : -1);
}