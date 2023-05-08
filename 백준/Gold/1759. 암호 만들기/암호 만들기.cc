#include <iostream>
#include <algorithm>
using namespace std;

int n,m; 
int vs[16],v[16];
char arr[16];

void dfs(int num, int cnt){
	if (cnt==n){
		int c=0,d=0;
		for (int i=0;i<n;i++)
			if (arr[v[i]]=='a' || arr[v[i]]=='e' || arr[v[i]]=='i' || arr[v[i]]=='o' || arr[v[i]]=='u') c++;
			else d++;
		if (c>0 && d>1){
			for (int i=0;i<n;i++) cout<<arr[v[i]];
			cout<<"\n";
		}
		return;
	}
	
	for (int i=num;i<m;i++){
		if (!vs[i]){
			vs[i]=1;
			v[cnt]=i;
			dfs(i+1,cnt+1);
			vs[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for (int i=0;i<m;i++) cin>>arr[i];
	
	sort(arr,arr+m);
	dfs(0,0);
}