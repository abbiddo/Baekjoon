#include <iostream>
using namespace std;
int main(){
	int s[10003]={0};
	int r[10003]={0};
	int n,i;
	
	cin>>n;
	
	for (i=3;i<n+3;i++) cin>>s[i];
	
	r[3]=s[3];
	r[4]=s[3]+s[4];
	
	for (i=5;i<n+3;i++) r[i]=max(s[i]+s[i-1]+r[i-3],max(s[i]+s[i-2]+s[i-3]+r[i-5],max(s[i-1]+s[i-2]+r[i-4],s[i]+s[i-2]+r[i-4])));
	
	cout<<r[n+2];
}