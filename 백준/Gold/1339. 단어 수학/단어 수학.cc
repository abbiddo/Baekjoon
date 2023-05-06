#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int len[10], al[26];
string s[10];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>s[i];
		len[i]=s[i].size();
	}
	
	for (int i=0;i<n;i++){
		int k=1;
		for (int j=len[i]-1;j>=0;j--){
			al[s[i][j]-'A']+=k;
			k*=10;
		}
	}
	
	sort (al,al+26,cmp);
	
	int re=0;
	for (int i=0;i<10;i++) re+=al[i]*(9-i);
	
	cout<<re;
}