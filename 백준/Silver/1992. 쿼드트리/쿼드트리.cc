#include <iostream>
using namespace std;
char arr[64][64];
int cnt[10];
int s=0,idx=0,a=0;
int paper(int x, int y, int n){
	int k=arr[x][y];
	a++;
	cnt[idx]++;	
	if (s==1) cout<<"(";
	
	for (int i=x;i<x+n;i++)
		for (int j=y;j<y+n;j++)
			if (k!=arr[i][j]){
				s=1;
				idx++;
				paper(x,y,n/2);
				s=2;
				paper(x,y+n/2,n/2);
				paper(x+n/2,y,n/2);
				paper(x+n/2,y+n/2,n/2);
				if (cnt[idx]==4) {
					cout<<")";
					cnt[idx]=0;
					idx--;
				}
				return 0;
			}
	s=0;
	
	if (s==0 && k==48) cout<<0;
	else if(s==0 && k==49) cout<<1;
	if (cnt[idx]==4) {
		cout<<")";
		cnt[idx]=0;
		idx--;
	}
	return 0;
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) cin>>arr[i][j];
		
	paper(0,0,n);
}