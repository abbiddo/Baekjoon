#include <vector>
#include <queue>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int solution(vector<vector<int> > maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    maps[0][0] = 3;
    q.push({0, 0});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int i = 0 ;i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (maps[nr][nc] != 1) continue;
            
            maps[nr][nc] = maps[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    return maps[n - 1][m - 1] - 2;
}