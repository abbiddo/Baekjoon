#include <iostream>
using namespace std;

int n, b, c, sum;
string s;   

int main(){
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>s;
        c = 0; sum = 0;
        for (int j = 0; j < s.size(); j++)
            if (s[j] == 'O') c++, sum+=c;
            else c = 0;
        cout<<sum<<"\n";
    }
}