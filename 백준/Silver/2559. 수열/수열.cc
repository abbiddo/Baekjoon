#include <iostream>
using namespace std;

int n, m;
int arr[100001];

int main() {
    cin>>n>>m;
    for (int i= 0 ; i < n; i++) cin>>arr[i];

    int sum = 0;
    for (int i = 0; i < m; i++) sum += arr[i];

    int s = 0, e = m, res = sum;
    while (e < n){
        sum -= arr[s++];
        sum += arr[e++];
        res = max(res, sum);
    }

    cout<<res;
}
