#include <iostream>
#include <algorithm>
using namespace std;
string p[500000];
string dp[500000];
string bp;

int search(int e){
	int s=0,mi;
	while(s<=e){
		mi=(s+e)/2;
		if (p[mi]<bp) s=mi+1;
		else if (p[mi]>bp) e=mi-1;
		else return mi;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,j=0,k;
	cin>>n>>m;
	
	for (int i=0;i<n;i++) cin>>p[i];
	
	sort(p,p+n);
	
	for (int i=0;i<m;i++){
		cin>>bp;
		k=search(n);
		if (k!=-1) dp[j++]=bp;
	}
	
	sort(dp,dp+j);
	
	cout<<j<<"\n";
	for (int i=0;i<j;i++) cout<<dp[i]<<"\n";
}