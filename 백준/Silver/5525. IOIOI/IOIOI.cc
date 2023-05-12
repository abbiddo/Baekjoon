#include <iostream>
using namespace std;
int n,t,ox,cnt=0;
string io;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
	
	cin>>n>>t>>io;
	
	for (int i=0;i<=t-(2*n+1);i++){
		ox=0;
		if (io[i]=='I'){
			int k=i;
			for (int j=0;j<2*n+1;j++){
				if (j%2==0 && io[k]=='I') k++;
				else if (j%2==1 && io[k]=='O') k++;
				else {
					ox=1;
					break;
				}
			}
			if (ox==0) cnt++;
		}
	}
	cout<<cnt;
}