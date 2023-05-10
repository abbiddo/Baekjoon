#include <iostream>
using namespace std;
int friends[101]={1000};
int relate[101][101];
int n,m,mi=1000,miii=1000;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		relate[a][b]=relate[b][a]=1;
	}
	
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i!=j){
					if (relate[i][k]!=0 && relate[k][j]!=0)	{
						if (relate[i][j]==0) relate[i][j]=relate[i][k]+relate[k][j];
						else relate[i][j]=min(relate[i][j],relate[i][k]+relate[k][j]);
					}
				}
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i!=j) friends[i]+=relate[i][j];
		}
	}
	
	for (int i=1;i<=n;i++){
		if (miii>friends[i]) {
			miii=friends[i];
			mi=i;
		}
	}
	cout<<mi;
}