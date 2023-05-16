#include <stdio.h>
#include <math.h>

void hanoi(int n, int a, int b, int c){
	if (n==1){
		printf("%d %d\n",a,c);
		return;
	}
	else{
		hanoi(n-1,a,c,b);
		hanoi(1,a,b,c);
		hanoi(n-1,b,a,c);
	}
} 

int main(){
	int n,re;
	scanf("%d",&n);
	re=pow(2,n)-1;
	printf("%d\n",re);
	
	hanoi(n,1,2,3);
}