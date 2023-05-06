#include <iostream>
#include <queue>
using namespace std;

int n,a,b;

void BFS(){
	int vs[10001]={0};
	queue<pair<int, string>> q;
	q.push({a,""});
	vs[a]=1;
	while(!q.empty()){
		int num=q.front().first;
		string st=q.front().second;
		q.pop();
		
		if (num==b){
			cout<<st<<"\n";
			return;
		}
		
		int D,S,L,R;
		
		D=(num*2)%10000; 
		if (!vs[D]){
			vs[D]=1;
			q.push({D,st+"D"});
		}
		
		if (num==0) S=9999;
		else S=num-1;
		if (!vs[S]){
			vs[S]=1;
			q.push({S,st+"S"});
		}
		
		L=(num/1000)+(num%1000)*10;
		if (!vs[L]){
			vs[L]=1;
			q.push({L,st+"L"});
		}
		
		R=(num/10)+(num%10)*1000;
		if(!vs[R]){
			vs[R]=1;
			q.push({R,st+"R"});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		BFS();
	}
}