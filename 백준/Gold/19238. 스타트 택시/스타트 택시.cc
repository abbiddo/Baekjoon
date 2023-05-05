#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
 
#define endl "\n"
#define MAX 25
using namespace std;

struct CUSTOMER {
    int x;
    int y;
    int Dest_x;
    int Dest_y;
};

struct INFO {
    int x;
    int y;
    int Dist;
    int Num;
};
 
int N, M, Fuel;
int Taxi_x, Taxi_y;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
CUSTOMER Customer[MAX * MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input() {
    cin >> N >> M >> Fuel;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) MAP[i][j] = -1;
        }
    
    cin >> Taxi_x >> Taxi_y;
    Taxi_x--; Taxi_y--;
    for (int i = 1; i <= M; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        Customer[i] = { a, b, c, d };
        MAP[a][b] = i;
    }
}
 
bool Info_Cmp(INFO A, INFO B) {
    if (A.Dist <= B.Dist) {
        if (A.Dist == B.Dist) {
            if (A.x <= B.x) {
                if (A.x == B.x) {
                    if (A.y < B.y)
                        return true;
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool BFS(int a, int b, int c, int d, int Num) {
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(0, Fuel)));
    Visit[a][b] = true;
 
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();
        
        if (Spare_Fuel < 0) return false;
        if (x == c && y == d) {
            Fuel = Fuel - Distance;
            Fuel = Fuel + (Distance * 2);
            Taxi_x = x;
            Taxi_y = y;
            return true;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
        }
    }
    return false;
}
 
int Find_Shortest_Customer() {
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(Taxi_x, Taxi_y), make_pair(0, Fuel)));
    Visit[Taxi_x][Taxi_y] = true;
    vector<INFO> V;
    
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();
 
        if (Spare_Fuel < 0) continue;
        if (MAP[x][y] >= 1) V.push_back({ x, y, Distance, MAP[x][y] });
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
        }
    }
    if (V.size() == 0) return -1;
 
    sort(V.begin(), V.end(), Info_Cmp);
    MAP[V[0].x][V[0].y] = 0;
    Fuel = Fuel - V[0].Dist;
    return V[0].Num;
}
 
void Solution() {
    for (int i = 0; i < M; i++) {
        int Num = Find_Shortest_Customer();
        if (Num == -1) {
            cout << -1 << endl;
            return;
        }
 
        bool Move = BFS(Customer[Num].x, Customer[Num].y, Customer[Num].Dest_x, Customer[Num].Dest_y, Num);
        if (Move == false) {
            cout << -1 << endl;
            return;
        }
    }
    cout << Fuel << endl;
}
 
void Solve() {
    Input();
    Solution();
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    Solve();
}