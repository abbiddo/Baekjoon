#include <iostream>
#include <algorithm>
using namespace std;
char arr[25][25];
int n,cnt=0,k;
int num[625];

int change(int i, int j){
	k++;
	arr[i][j]=0;
	if (arr[i+1][j]==1 && i<n-1) change(i+1,j);
	if (arr[i-1][j]==1 && i>0) change(i-1,j);
	if (arr[i][j+1]==1 && j<n-1) change(i,j+1);
	if (arr[i][j-1]==1 && j>0) change(i,j-1);
	return k;
}

int apartment(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (arr[i][j]==1){
				cnt++;
				k=0;
				num[cnt]=change(i,j);
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
			arr[i][j]-=48;
		}
	}
	cnt=0;
	apartment();
	cout<<cnt<<'\n';
	sort(num+1,num+cnt+1);
	for (int i=1;i<=cnt;i++) cout<<num[i]<<"\n";	
}