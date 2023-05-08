#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,s,temp,mi=1000001;
	int arr[50];
	
	cin>>n;
	for (int i=0;i<n;i++) cin>>arr[i];
	cin>>s;
	
	for (int i=0;i<n-1;i++){
		int ma=0,m=0;
		for (int j=i;j<n;j++)
			if (ma<arr[j] && mi>arr[j]) {
				ma=arr[j];
				m=j;
			}
		mi=ma;
			
		if (m-i>s) {
			i--;
			continue;
		}
		mi=1000001;
		for (int j=m;j>i;j--){
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			s--;
		}
		
		if (s==0) break;
	}
	for (int k=0;k<n;k++) cout<<arr[k]<<" ";
}