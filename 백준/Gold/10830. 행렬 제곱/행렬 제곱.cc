#include <iostream>
using namespace std;

int n;
long long b;
int arr[5][5],ans[5][5];

void rc(int x[5][5]){
	int temp[5][5]={0};
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				temp[i][j]+=x[i][k]*arr[k][j];
			}
			temp[i][j]%=1000;
		}
	}
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			x[i][j]=temp[i][j];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>b;
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) 
			cin>>arr[i][j];	
		ans[i][i]=1;
	}
	
	while(b>0){
		if (b%2==1) rc(ans);
		rc(arr);
		b/=2;
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) cout<<ans[i][j]<<" ";
		cout<<"\n";
	}		
}