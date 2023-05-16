#include <iostream>
using namespace std;
int n,arr[100][100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) cin>>arr[i][j];
		
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (arr[i][k]+arr[k][j]==2){
					arr[i][j]=1;
					break;
				}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (arr[i][k]+arr[k][j]==2){
					arr[i][j]=1;
					break;
				}
				
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
}