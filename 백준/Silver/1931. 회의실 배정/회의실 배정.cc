#include <iostream>
#include <algorithm>
using namespace std;

class time{
	public:
		int s,f;
};

time *t=new time[100000];

int cmp(time a, time b){
	if (a.f==b.f) return a.s<b.s;
	return a.f<b.f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m=0,f=0;
	cin>>n;
  	
	for (int i=0;i<n;i++) cin>>t[i].s>>t[i].f;
	
	sort(t,t+n,cmp);

    for(int i=0;i<n;i++)
	    if(t[i].s>=f){
        f=t[i].f;
		m++;
    	}
    cout<<m;
}