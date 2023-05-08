#include <iostream>
#include <algorithm>
using namespace std;
char arr[100][100];
char color[100][100];
int n,cnt=0,ccnt=0;

int RGB(int i, int j, char rgb){
	arr[i][j]=0;
	if (arr[i+1][j]==rgb && i<n-1) RGB(i+1,j,rgb);
	if (arr[i-1][j]==rgb && i>0) RGB(i-1,j,rgb);
	if (arr[i][j+1]==rgb && j<n-1) RGB(i,j+1,rgb);
	if (arr[i][j-1]==rgb && j>0) RGB(i,j-1,rgb);
	return 0;
}

int RGB2(int i, int j, char rgb){
	color[i][j]=0;
	if (color[i+1][j]==rgb && i<n-1) RGB2(i+1,j,rgb);
	if (color[i-1][j]==rgb && i>0) RGB2(i-1,j,rgb);
	if (color[i][j+1]==rgb && j<n-1) RGB2(i,j+1,rgb);
	if (color[i][j-1]==rgb && j>0) RGB2(i,j-1,rgb);
	return 0;
}

int Color(){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (arr[i][j]=='R'){
				cnt++;
				RGB(i,j,'R');
			}
			if (arr[i][j]=='G'){
				cnt++;
				RGB(i,j,'G');
			}
			if (arr[i][j]=='B'){
				cnt++;
				RGB(i,j,'B');
			}
		}
	
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (color[i][j]=='R'){
				ccnt++;
				RGB2(i,j,'R');
			}
			if (color[i][j]=='B'){
				ccnt++;
				RGB2(i,j,'B');
			}
		}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
			if (arr[i][j]=='G') color[i][j]='R';
			else color[i][j]=arr[i][j];
		}
			
	Color();
	cout<<cnt<<" "<<ccnt;	
}