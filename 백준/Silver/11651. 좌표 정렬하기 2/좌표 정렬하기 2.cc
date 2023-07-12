#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100000];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin>>n;
    for (int i = 0; i < n; i++){
        int x, y;    cin >> x >> y;
        arr[i] = {y, x};
    }
    sort(arr, arr+n);
    
    for (int i = 0; i < n; i++) cout << arr[i].second << " " << arr[i].first << "\n";
}