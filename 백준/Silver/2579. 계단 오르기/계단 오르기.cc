#include <iostream>
using namespace std;
int main(){
	int s[301]={0};
	int r[301]={0};
	int n,i;
	
	cin>>n;
	
	for (i=1;i<=n;i++) cin>>s[i];
	
	r[1]=s[1];
	r[2]=s[1]+s[2];
	
	for (i=3;i<=n;i++) r[i]=s[i]+max(s[i-1]+r[i-3],r[i-2]);
	
	cout<<r[n];
}