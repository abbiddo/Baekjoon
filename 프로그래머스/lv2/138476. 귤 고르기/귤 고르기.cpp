#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10000001] = {};

bool cmp(int a, int b){
    return a>b;
}
int solution(int k, vector<int> tangerine) {
    for(int i = 0; i < tangerine.size(); i++) arr[tangerine[i]]++;
    sort(arr, arr+10000001, cmp);
    
    int answer = 0;
    int cnt = 0;
    int index = 0;
    while(cnt<k){
        cnt+=arr[index++];
        answer++;
    }
    return answer;
}
