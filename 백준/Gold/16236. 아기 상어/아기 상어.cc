#include <iostream>
using namespace std;
int n,x,y,sec,shark=2,scnt=0,c=1,cc;
int arr[20][20], fish[400][3], num[400][2], num2[400][2], maze[20][20];

int ok(){
	int k=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (arr[i][j]!=0 && arr[i][j]<shark){
				fish[k][0]=shark;
				fish[k][1]=i;
				fish[k][2]=j;
				k++;
			}
	return k;
}

int sear(int i, int j){
	for (int k=0;k<cc;k++)
		if (num[k][0]==i && num[k][1]==j) return 0;
	return 1;
}

int change(int i, int j){
	if (i<n-1 && maze[i+1][j]!=0) {
		if (maze[i+1][j]==1) maze[i+1][j]+=maze[i][j];
		else maze[i+1][j]=min(maze[i+1][j],maze[i][j]+1);
		if (sear(i+1,j)){
			num[cc][0]=i+1;
			num[cc][1]=j;
			cc++;
		}
	}
	if (i>0 && maze[i-1][j]!=0) {
		if (maze[i-1][j]==1) maze[i-1][j]+=maze[i][j];
		else maze[i-1][j]=min(maze[i-1][j],maze[i][j]+1);
		if (sear(i-1,j)){
			num[cc][0]=i-1;
			num[cc][1]=j;
			cc++;
		}
	}
	if (j<n-1 && maze[i][j+1]!=0) {
		if (maze[i][j+1]==1) maze[i][j+1]+=maze[i][j];
		else maze[i][j+1]=min(maze[i][j+1],maze[i][j]+1);
		if (sear(i,j+1)){
			num[cc][0]=i;
			num[cc][1]=j+1;
			cc++;
		}
	}
	if (j>0 && maze[i][j-1]!=0) {
		if (maze[i][j-1]==1) maze[i][j-1]+=maze[i][j];
		else maze[i][j-1]=min(maze[i][j-1],maze[i][j]+1);
		if (sear(i,j-1)){
			num[cc][0]=i;
			num[cc][1]=j-1;
			cc++;
		}
	}
	maze[i][j]=0;
	return 0;
}

int distance(int k){
	for (int i=0;i<c;i++){
		change(num2[i][0],num2[i][1]);
		if (maze[fish[k][1]][fish[k][2]]!=1) return 0;
	}		
		
	for (int i=0;i<cc;i++){
		num2[i][0]=num[i][0];
		num2[i][1]=num[i][1];
	}
	
	return 0;
}

int mini(int k){
	int mi=800,xx,yy;
	int disx,disy;
	
	for (int i=0;i<k;i++){
		disx=abs(fish[i][1]-x);
		disy=abs(fish[i][2]-y);
		
		for (int a=0;a<n;a++)
			for (int b=0;b<n;b++) {
				if (arr[a][b]>shark) maze[a][b]=0;
				else maze[a][b]=1;
			}
			
		num2[0][0]=x;
		num2[0][1]=y;		
		c=1;
		for (int j=0;j<n*n;j++){
			if (maze[fish[i][1]][fish[i][2]]!=1) break;
			distance(i);
			c=cc;
			cc=0;
		}
		
		if (maze[fish[i][1]][fish[i][2]]!=1 && maze[fish[i][1]][fish[i][2]]<mi){
			xx=fish[i][1];
			yy=fish[i][2];
			mi=maze[fish[i][1]][fish[i][2]];
		}
	}
	
	if (mi!=800){
		sec+=(mi-1);
		scnt++;
		arr[xx][yy]=0;
		x=xx;
		y=yy;
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			cin>>arr[i][j];
			if (arr[i][j]==9){
				x=i;
				y=j;
				arr[i][j]=0;
			}
		}
		
	for (int i=0;i<n*n;i++){
		int k=ok();
		if (!k) break;
		mini(k);
		if (scnt==shark){
			shark++;
			scnt=0;
		}
	}
	
	cout<<sec;
}