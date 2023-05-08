#include <iostream>
using namespace std;
int n,m,f,b,cnt,con;
char t;
int arr[700000];
string order;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++){
		cnt=con=f=0;
		cin>>order;
		cin>>m;
		b=m-1;
		cin>>t;
		if (m==0) cin>>t;
		else for (int j=0;j<m;j++) cin>>arr[j]>>t;
		for (int j=0;j<order.size();j++){
			if (order[j]=='R') cnt++;
			else{
				if (cnt%2==0) arr[f++]=0;
				else arr[b--]=0;
			}
			if (f==b+1) con=10;
			else if (f==b+2){
				cout<<"error\n";
				con=1000;
				break;
			}
		}
		if (con==10) cout<<"[]\n";
		else if (con!=1000){
			cout<<"[";
			if (cnt%2==0) {
				for (int k=f;k<=b-1;k++) cout<<arr[k]<<",";
				cout<<arr[b]<<"]\n";
			}
			else {
				for (int k=b;k>f;k--) cout<<arr[k]<<",";
				cout<<arr[f]<<"]\n";
			}
		
		}
	}
}