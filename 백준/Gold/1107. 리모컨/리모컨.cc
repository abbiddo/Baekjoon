#include <iostream>
#include <string>
using namespace std;
string arr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a[10],kk=0,mi;
	cin>>arr>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	
	int k=stoi(arr);
	
	if (k==100){
		cout<<0;
		return 0;
	}
	
	if (k<100) mi=100-k;
	if (k>100) mi=k-100;
	
	for (int i=k;i<1000001;i++){
		kk=0;
		string m=to_string(i);
		for (int j=0;j<m.size();j++){
			for (int jj=0;jj<n;jj++){
				if (m[j]-48==a[jj]){
					kk=1;
					break;
				}
			}
			if (kk==1) break;
		}
		if (kk==0) {
			if (mi>i-k+m.size()) mi=i-k+m.size();
			break;
		}
	}
	
	for (int i=k;i>=0;i--){
		kk=0;
		string m=to_string(i);
		for (int j=0;j<m.size();j++){
			for (int jj=0;jj<n;jj++){
				if (m[j]-48==a[jj]){
					kk=1;
					break;
				}
			}
			if (kk==1) break;
		}
		if (kk==0) {
			if (mi>k-i+m.size()) mi=k-i+m.size();
			break;
		}
	}
	cout<<mi;
}