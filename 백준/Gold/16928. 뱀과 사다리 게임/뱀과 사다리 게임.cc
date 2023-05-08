#include <iostream>
#include <queue>
using namespace std;

int n,m,x,y; 
int board[101],d[101];
void BFS(){
	d[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for (int i=1;i<7;i++){
			int y=x+i;
			if (y>100) continue;
			y=board[y];
			if (d[y]==-1){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i=1;i<101;i++)	{
		d[i]=-1;
		board[i]=i;
	}
	
	cin>>n>>m;
	for (int i=0;i<n+m;i++){
		cin>>x>>y;
		board[x]=y;
	}
	
	BFS();
	cout<<d[100];
}