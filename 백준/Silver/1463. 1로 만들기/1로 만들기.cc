#include <iostream>
using namespace std;

int a[1000001]={0,0,1,1};
int n,i;

int main(){
	cin>>n;
	
	for (i=4;i<=n;i++){
		if (i%2!=0 && i%3!=0) a[i]=a[i-1]+1;
		else if (i%6==0) a[i]=min(a[i/2],a[i/3])+1;
		else if (i%3==0) a[i]=min(a[i/3],a[i-1])+1;
		else if (i%2==0) a[i]=min(a[i/2],a[i-1])+1;
	}
	
	cout<<a[n];
}