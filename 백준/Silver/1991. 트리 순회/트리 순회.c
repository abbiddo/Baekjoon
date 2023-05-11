#include <stdio.h>

int arr[26][2];

// 전위 순회
void preorder(int x) {
	if (x<0) return;
	printf("%c", x+65);
	preorder(arr[x][0]);
	preorder(arr[x][1]);
}

// 중위 순회
void inorder(int x) {
	if (x<0) return;
	inorder(arr[x][0]);  // 왼쪽 서브 트리 순회
	printf("%c", x+65);  // 노드 데이터 출력
	inorder(arr[x][1]);  // 오른쪽 서브 트리 순회
}

// 후위 순회
void postorder(int x) {
	if (x<0) return;
	postorder(arr[x][0]);
	postorder(arr[x][1]);
	printf("%c", x+65);
}

int main() {
	int n,i;
	scanf("%d",&n);
		
	for (i=0;i<n;i++){
		char a,b,c;
		scanf("\n%c \n%c \n%c",&a,&b,&c);
		
		arr[a-'A'][0]=b-'A';
		arr[a-'A'][1]=c-'A';
	}
	
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}
