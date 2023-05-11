#include <iostream>
using namespace std;

int n,cnt;
int arr[1000];
string car[1000];
string c;
 
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>car[i];
	
	for (int i=0;i<n;i++){
		cin>>c;
		for (int j=0;j<n;j++){
			if (car[j]==c){
				arr[i]=j;
				break;
			}
		}
	}
	
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if (arr[i]>arr[j]){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
}