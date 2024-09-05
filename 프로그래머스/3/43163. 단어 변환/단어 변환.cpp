#include <string>
#include <vector>
#include <queue>

using namespace std;

struct alpha{
    int n;
    string t;
    string w;
};

int solution(string begin, string target, vector<string> words) {   
    int size = begin.size();
    queue<alpha> q;
    q.push({0, begin, begin+"-"});
    
    while(!q.empty()){
        alpha a = q.front();
        q.pop();
        
        if (a.t == target) return a.n;
        
        for (int i = 0; i < words.size(); i++){
            int cnt = 0;
            for (int j = 0; j < size; j++){
                if (a.t[j] != words[i][j]) cnt++;
            }
            
            if (cnt != 1) continue;
            if (a.w.find(words[i]) != string::npos) continue;
            q.push({a.n + 1, words[i], a.w + words[i] + "-"});
        }
    }
    
    return 0;
}