#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int arr[10]={0};
	long long n,re,k,m=0,jj=1;
	cin>>n;
	
	k=n;
	while(k){
		arr[k%10]=1;
		m=max(m,k%10);
		k/=10;
	}
	
	re=n;
	while(1){
		for (int i=1;i<=m;i++){
			if (arr[i]==1){
				if (re%i!=0) break;
				if (i==m && re%i==0){
					cout<<re;
					return 0;
				}
			}
		}
		re++;
		if (re%jj==0){
			re-=jj;
			re*=10;
			jj*=10;
		}
	}
}