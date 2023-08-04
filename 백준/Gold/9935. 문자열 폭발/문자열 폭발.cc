#include <iostream>
#include <deque>
using namespace std;

int s;
string st, bumb;
deque<char> d, re;

void de(){
	while(!d.empty()){
		int i=0;
		string c="";
		c+=d.front();
		d.pop_front();
		
		if (c[0]==bumb[0]){
			for (int j=1;j<bumb.size();j++){
				if (d.empty()) break;
				c+=d.front();
				d.pop_front();
			}
			
			if (c==bumb){
				c="";
				for (int k=0;k<bumb.size();k++){
					if (re.empty()) break;
					c=re.back()+c;
					re.pop_back();
				}
				for (int k=c.size()-1;k>=0;k--){
					d.push_front(c[k]);
				}
			}
			else{
				re.push_back(c[0]);
				for (int k=c.size()-1;k>0;k--) d.push_front(c[k]);
			}
		}
		else{
			re.push_back(c[0]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>st;
	for (int i=0;i<st.size();i++) d.push_back(st[i]);
	
	cin>>bumb;
	
	de();
	if (re.empty()) cout<<"FRULA";
	else{
		while(!re.empty()){
			cout<<re.front();
			re.pop_front();
		}
	}
}