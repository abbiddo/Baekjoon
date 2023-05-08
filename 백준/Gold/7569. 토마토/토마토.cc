#include <iostream>
using namespace std;
int arr[100][100][100];
int num[1000001][3];
int num2[1000001][3];
int n,m,h,c=0,cc=0,day=0,zcnt=0;

int change(int i, int j, int k){
	arr[i][j][k]=-1;
	if (i<h-1 && arr[i+1][j][k]==0) {
		arr[i+1][j][k]=1;
		num[cc][0]=i+1;
		num[cc][1]=j;
		num[cc][2]=k;
		cc++;
		zcnt--;
	}
	if ( i>0 && arr[i-1][j][k]==0) {
		arr[i-1][j][k]=1;
		num[cc][0]=i-1;
		num[cc][1]=j;
		num[cc][2]=k;
		cc++;
		zcnt--;
	}
	if (j<n-1 && arr[i][j+1][k]==0) {
		arr[i][j+1][k]=1;
		num[cc][0]=i;
		num[cc][1]=j+1;
		num[cc][2]=k;
		cc++;
		zcnt--;
	}
	if (j>0 && arr[i][j-1][k]==0) {
		arr[i][j-1][k]=1;
		num[cc][0]=i;
		num[cc][1]=j-1;
		num[cc][2]=k;
		cc++;
		zcnt--;
	}
	if (k<m-1 && arr[i][j][k+1]==0) {
		arr[i][j][k+1]=1;
		num[cc][0]=i;
		num[cc][1]=j;
		num[cc][2]=k+1;
		cc++;
		zcnt--;
	}
	if (k>0 && arr[i][j][k-1]==0) {
		arr[i][j][k-1]=1;
		num[cc][0]=i;
		num[cc][1]=j;
		num[cc][2]=k-1;
		cc++;
		zcnt--;
	}
	return 0;
}

int tomato(){
	for (int i=0;i<c;i++)
		change(num2[i][0],num2[i][1],num2[i][2]);
		
	for (int i=0;i<cc;i++){
		num2[i][0]=num[i][0];
		num2[i][1]=num[i][1];
		num2[i][2]=num[i][2];
	}
		
	day++;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>m>>n>>h;
	for (int k=0;k<h;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				cin>>arr[k][i][j];
				if (arr[k][i][j]==0) zcnt++;
				else if (arr[k][i][j]==1){
					num2[c][0]=k;
					num2[c][1]=i;
					num2[c][2]=j;
					c++;
				}
			}
			
	for (int i=0;i<((n*m)*h);i++) {
		if (zcnt==0){
			cout<<day;
			return 0;
		}
		tomato();
		c=cc;
		cc=0;
	}
	cout<<-1;
}