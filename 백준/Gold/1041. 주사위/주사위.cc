#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n,sum=0;
	cin>>n;
	
	long long arr[6];
	for (int i=0;i<6;i++) cin>>arr[i];
	
	if (n==1){
		sort(arr,arr+6);
		for (int i=0;i<5;i++) sum+=arr[i];
		cout<<sum;
		return 0;
	}
	
	long long a[4]={0,200,200,200};
	a[3]=min(arr[0]+arr[1]+arr[2],a[3]);
	a[3]=min(arr[0]+arr[1]+arr[3],a[3]);
	a[3]=min(arr[0]+arr[2]+arr[4],a[3]);
	a[3]=min(arr[0]+arr[3]+arr[4],a[3]);
	a[3]=min(arr[1]+arr[2]+arr[5],a[3]);
	a[3]=min(arr[1]+arr[3]+arr[5],a[3]);
	a[3]=min(arr[2]+arr[4]+arr[5],a[3]);
	a[3]=min(arr[3]+arr[4]+arr[5],a[3]);
	
	a[2]=min(arr[0]+arr[1],a[2]);
	a[2]=min(arr[0]+arr[2],a[2]);
	a[2]=min(arr[0]+arr[3],a[2]);
	a[2]=min(arr[0]+arr[4],a[2]);
	a[2]=min(arr[1]+arr[2],a[2]);
	a[2]=min(arr[1]+arr[3],a[2]);
	a[2]=min(arr[1]+arr[5],a[2]);
	a[2]=min(arr[2]+arr[4],a[2]);
	a[2]=min(arr[2]+arr[5],a[2]);
	a[2]=min(arr[3]+arr[4],a[2]);
	a[2]=min(arr[3]+arr[5],a[2]);
	a[2]=min(arr[4]+arr[5],a[2]);
	
	sort(arr,arr+6);
	
	sum+=a[3]*4;
	sum+=a[2]*(8*n-12);
	sum+=arr[0]*(5*n*n-16*n+12);
	
	cout<<sum;
}