#include <iostream>
#include <queue>
using namespace std;
int n,m;
int visit[100001];

int BFS(){
	queue<int> q;
	q.push(n);
	visit[n]=1;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if (p==m) return visit[p]-1;
		
		if (p-1>=0 && visit[p-1]==0){
			q.push(p-1);
			visit[p-1]=visit[p]+1;
		}
		
		if (p+1<=100000 && visit[p+1]==0){
			q.push(p+1);
			visit[p+1]=visit[p]+1;
		}
		
		if (p*2<=100000 && visit[p*2]==0){
			q.push(p*2);
			visit[p*2]=visit[p]+1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
		
	cout<<BFS();
}