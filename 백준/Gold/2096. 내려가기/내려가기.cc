#include <iostream>
using namespace std;

int n,ma[3],mi[3],a,b,c,x,y,z;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	cin>>a>>b>>c;
	ma[0]=mi[0]=a; ma[1]=mi[1]=b; ma[2]=mi[2]=c;
	
	for (int i=1;i<n;i++) {
		cin>>a>>b>>c;
		x=ma[0]; y=ma[1], z=ma[2];
		ma[0]=a+max(x,y);
		ma[1]=b+max(x,max(y,z));
		ma[2]=c+max(y,z);
		
		x=mi[0]; y=mi[1], z=mi[2];
		mi[0]=a+min(x,y);
		mi[1]=b+min(x,min(y,z));
		mi[2]=c+min(y,z);
	}
	
	cout<<max(ma[0],max(ma[1],ma[2]))<<" "<<min(mi[0],min(mi[1],mi[2]));
}