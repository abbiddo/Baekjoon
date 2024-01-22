#include <stdio.h>

void push(int a);              // 함수 선언
void pop();

int S[100000];
int i = 0;

int main() {
	int n,j,m,sum=0;

	scanf("%d", &n);            // 명령 횟수 입력

	for (j = 0; j < n; j++) {
		scanf("%d", &m);
		if (m == 0) pop();      // pop 함수 실행
		else push(m);
	}

	for (j = 0; j < i; j++)
		sum += S[j];

	printf("%d", sum);
}

void push(int a) {                                                   
	S[i++] = a;                         // 스택 배열에 데이터 추가 후 i를 증가시켜 다음 인덱스 가리킴
}

void pop() {
	i--;
}