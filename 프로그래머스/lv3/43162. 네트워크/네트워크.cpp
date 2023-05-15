#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int arr[200] = {0};
    
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            queue<int> q;
            q.push(i);
            answer++;
            while(!q.empty()){
                int c = q.front();
                q.pop();
                
                for (int index = 1; index < n; index++){
                    if (computers[c][index] == 0) continue;
                    if (arr[index]) continue;
                    arr[index] = 1;
                    q.push(index);
                }
            }
        }
    }
    return answer;
}