#include <iostream>
using namespace std;
int main(){
	int rgb[1001][3]={0};
	int r[1001][3]={0};
	int n,i;
	
	cin>>n;
	
	for (i=1;i<=n;i++)
		for (int j=0;j<3;j++) cin>>rgb[i][j];
		
	for (i=1;i<=n;i++){
		r[i][0]=rgb[i][0]+min(r[i-1][1],r[i-1][2]);
		r[i][1]=rgb[i][1]+min(r[i-1][0],r[i-1][2]);
		r[i][2]=rgb[i][2]+min(r[i-1][1],r[i-1][0]);
	}
	
	cout<<min(r[n][0],min(r[n][1],r[n][2]));
}