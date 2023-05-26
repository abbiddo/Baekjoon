#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,cnt=0;
	unsigned long long re=1;
	cin>>n;
	
	for (int i=1;i<=n;i++){
		re*=i;
		while(re%10==0){
			cnt++;
			re/=10;
		}
		if (re>99999) re%=100000;
	}
	cout<<cnt;
}