#include <iostream>
using namespace std;

int n,arr[4000001]={1,1},prime[4000001],a=1,sum,k=1,kk=0,cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	if (n==1){
		cout<<0;
		return 0;
	}
	
	if (n==2){
		cout<<1;
		return 0;
	}
	
	for (int i=2;i<=n;i++){
		if (arr[i]==0){
			prime[a]=prime[a-1]+i;
			a++;
			for (int j=2;j*i<=n;j++) arr[i*j]=1;
		}
	}
	
	if (n<4){
		prime[0]=2;
		prime[1]=3;
	}
	
	while(k>=kk && k<=a){
		if (prime[k]-prime[kk]<n) k++;		
		else if (prime[k]-prime[kk]>n)  kk++;
		else {
			cnt++;
			k++;
		}
	}
	cout<<cnt;
}