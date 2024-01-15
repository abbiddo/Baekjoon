#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	char a[50][50];
	int n,m,r,c;
	cin>>n>>m;
	
	r=n;
	c=m;
	 
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) cin>>a[i][j];
	
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (a[i][j]=='X'){
				r--;
				break;
			}
	
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (a[j][i]=='X'){
				c--;
				break;
			}
			
	printf("%d",r<c?c:r);
}