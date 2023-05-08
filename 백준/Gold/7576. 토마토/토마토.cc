#include <iostream>
using namespace std;
int arr[1000][1000];
int num[1000000][2];
int num2[1000000][2];
int n,m,k=1,c=0,cc=0,day=0,zcnt=0;

int change(int i, int j){
	arr[i][j]=-1;
	if (arr[i+1][j]==0 && i<n-1) {
		arr[i+1][j]=1;
		num[cc][0]=i+1;
		num[cc][1]=j;
		cc++;
		zcnt--;
	}
	if (arr[i-1][j]==0 && i>0) {
		arr[i-1][j]=1;
		num[cc][0]=i-1;
		num[cc][1]=j;
		cc++;
		zcnt--;
	}
	if (arr[i][j+1]==0 && j<m-1) {
		arr[i][j+1]=1;
		num[cc][0]=i;
		num[cc][1]=j+1;
		cc++;
		zcnt--;
	}
	if (arr[i][j-1]==0 && j>0) {
		arr[i][j-1]=1;
		num[cc][0]=i;
		num[cc][1]=j-1;
		cc++;
		zcnt--;
	}
	return 0;
}

int tomato(){
	for (int i=0;i<c;i++)
		change(num2[i][0],num2[i][1]);
		
	for (int i=0;i<cc;i++){
		num2[i][0]=num[i][0];
		num2[i][1]=num[i][1];
	}
		
	day++;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>m>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			cin>>arr[i][j];
			if (arr[i][j]==0) zcnt++;
			else if (arr[i][j]==1){
				num2[c][0]=i;
				num2[c][1]=j;
				c++;
			}
		}
		
	for (int i=0;i<n*m/3*2;i++)	{
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