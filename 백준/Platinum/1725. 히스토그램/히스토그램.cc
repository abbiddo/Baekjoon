#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> s;
int arr[100002];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    s.push(0);

    int re = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (!s.empty()) {
            int top = s.top();

            if (arr[top] <= arr[i]) break;

            s.pop();

            re = max(re, arr[top] * (i - s.top() - 1));
        }
        s.push(i);
    }

    cout << re;
}