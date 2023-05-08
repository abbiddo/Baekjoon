#include <stdio.h>
int star(int a);
int kk[6561][6561]={0,};
int main(){
	int a,i,j;
	scanf("%d",&a);
	star(a);
	
	for (i=0;i<a;i++){
		for (j=0;j<a;j++){
			if (kk[i][j]==0) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
int star(int n){
	int a,i,j,ii,jj,s=n;
	a=n;
	while (1){
	for (i=0;i<a;i++)
		for (j=0;j<a;j++)
			if ((i>(s/3-1)&&i<s-s/3))
				if ((j>(s/3-1)&&j<s-s/3))
					for (ii=i;ii<a;ii+=s)
						for (jj=j;jj<a;jj+=s)
							kk[ii][jj]=1;
	s/=3;
	if (s==1) break;
	}
}