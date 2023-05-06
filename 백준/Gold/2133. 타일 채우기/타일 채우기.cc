#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int arr[16]={3,11};
	cin>>n;
	
	if (n%2==1) cout<<0;
	else {
		for (int i=2;i<n/2;i++) arr[i]=4*arr[i-1]-arr[i-2];
		cout<<arr[n/2-1];
	}
}