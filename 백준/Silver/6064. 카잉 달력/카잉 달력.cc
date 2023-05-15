#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,M,N,x,y,k;
	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>M>>N>>x>>y;
		k=0;x--;y--;
		
		for (int j=x;j<(M*N);j+=M){
			if (j%N==y){
				cout<<j+1<<"\n";
				k=1;
				break;
			}
		}
		if (!k) cout<<"-1\n";
	} 
}