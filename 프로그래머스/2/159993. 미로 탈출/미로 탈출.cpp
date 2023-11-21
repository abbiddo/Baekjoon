#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
    
int n, m, r, c, lr, lc;
int eSave = 0;

int toLever(vector<string> maps){
    
    int visit[100][100];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            visit[i][j] = 0;
        }
    }
    
    queue<pair<int, int>> q;    
    q.push({r, c});
    
    while (!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int ar = rr + dr[i];
            int ac = cc + dc[i];
            
            if (ar < 0 || ar >= n || ac < 0 || ac >= m) continue;
            if (maps[ar][ac] == 'X') continue;
            if (maps[ar][ac] == 'L') return visit[rr][cc] + 1;
            if (visit[ar][ac]) continue;
            
            visit[ar][ac] = visit[rr][cc] + 1;
            q.push({ar, ac});
        }
    }
    return -1;
}

int toExit(vector<string> maps, int cnt){
    
    int visit[100][100];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            visit[i][j] = 0;
        }
    }
    
    visit[lr][lc] = cnt;
    
    queue<pair<int, int>> q;    
    q.push({lr, lc});
    
    while (!q.empty()){
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int ar = rr + dr[i];
            int ac = cc + dc[i];
            
            if (ar < 0 || ar >= n || ac < 0 || ac >= m) continue;
            if (maps[ar][ac] == 'X') continue;
            if (maps[ar][ac] == 'E') return visit[rr][cc] + 1;            
            if (visit[ar][ac]) continue;
            
            visit[ar][ac] = visit[rr][cc] + 1;
            q.push({ar, ac});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maps[i][j] == 'S'){
                r = i;
                c = j;
            }
            if (maps[i][j] == 'L'){
                lr = i;
                lc = j;
            }
        }
    }
    
    int a = toLever(maps);
    if (a == -1) return a;
    if (eSave != 0) return a + eSave;
    return toExit(maps, a);
}