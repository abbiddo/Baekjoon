#include <iostream>
using namespace std;

int n,m;
int arr[9];
int vs[9];

void dfs(int num, int cnt){
	if (cnt==m){
		for (int i=0;i<m;i++) cout<<arr[i]<<" ";
		cout<<"\n";
		return;
	}
	for (int i=1;i<=n;i++){
		if (!vs[i]){
			vs[i]=1;
			arr[cnt]=i;
			dfs(i+1,cnt+1);
			vs[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	dfs(1,0);
}