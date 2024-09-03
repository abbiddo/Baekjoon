#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int k, vector<vector<int>>& d, vector<bool>& visited, int count) {
    int maxCount = count;

    for (int i = 0; i < d.size(); i++) {
        if (!visited[i] && k >= d[i][0]) { 
            visited[i] = true;
            maxCount = max(maxCount, dfs(k - d[i][1], d, visited, count + 1));
            visited[i] = false;
        }
    }

    return maxCount;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    return dfs(k, dungeons, visited, 0);
}