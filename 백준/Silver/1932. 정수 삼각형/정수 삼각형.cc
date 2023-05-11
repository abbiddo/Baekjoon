#include <iostream>
using namespace std;
int main(){
	int n,i,j,m=0;
	int t[500][500]={0,};
	int re[500][500]={0};
	
	cin>>n;
	
	for (i=0;i<n;i++)
		for (j=0;j<=i;j++) cin>>t[i][j];
		
	re[0][0]=t[0][0];
	
	for (i=1;i<n;i++){
		for (j=0;j<=i;j++){
			if (j==0) re[i][j]=re[i-1][j]+t[i][j];
			else if (i==j) re[i][j]=re[i-1][j-1]+t[i][j];
			else re[i][j]=t[i][j]+max(re[i-1][j],re[i-1][j-1]);
		}
	}
	
	for (i=0;i<n;i++)
		if (m<re[n-1][i]) m=re[n-1][i];
	
	cout<<m;
}