#include <iostream>
using namespace std;

int arr[100001], n, ma, count;

int main() {
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=n-1; i>=0; i--)
        if(ma < arr[i]) {
            count++;
            ma=arr[i];
        }
    cout<<count;
}