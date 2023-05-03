#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
pair<int, int> arr[200000];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;   cin >> s >> e;
        arr[i] = { s,e };
    }

    sort(arr, arr + n);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int s = arr[i].first;
        pq.push(arr[i].second);
        if (pq.top() > s) cnt++;
        else pq.pop();
    }

    cout << cnt;
}