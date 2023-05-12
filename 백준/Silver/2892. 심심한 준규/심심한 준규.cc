#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int n;    cin>>n;
    for (int i = 0 ; i< n; i ++){
        string chHex;    cin>>chHex;
        int a = stoi(chHex, NULL, 16);
        if (a >= 64 && a<= 95) cout<<"-";
        else cout<<".";
    }
}