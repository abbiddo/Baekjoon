#include <stdio.h>
#include <math.h>
int main(){
	int n,i,x,y,z,j;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		z=y-x;
		j=round(sqrt(z));
		if (sqrt(z)<=j) printf("%d\n",2*j-1);
		else printf("%d\n",2*j);
	}
}