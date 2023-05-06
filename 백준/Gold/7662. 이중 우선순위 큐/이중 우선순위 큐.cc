#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,k;
	char a;
	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>m;
		int arr[1000000]={0};
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> iq;
		priority_queue<pair<int,int>> aq;
		for (int j=0;j<m;j++){
			cin>>a>>k;
			if (a=='I'){
				iq.push({k,j});
				aq.push({k,j});
				arr[j]=1;
			}
			else if (a=='D'){
				if (k==1){
					if (aq.size()!=0) {
						arr[aq.top().second]=0;
						aq.pop();
					}
				}
				else{
					if (iq.size()!=0){
						arr[iq.top().second]=0;
						iq.pop();
					}
				}
			}
			if (iq.size()!=0) while(!arr[iq.top().second] && iq.size()!=0) iq.pop();
			if (aq.size()!=0) while(!arr[aq.top().second] && aq.size()!=0) aq.pop();	
		}
		if (aq.size()==0 || iq.size()==0) cout<<"EMPTY\n";
		else cout<<aq.top().first<<" "<<iq.top().first<<"\n";
	}
}