#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    int count = queue1.size() * 3;
    queue<long long> q1, q2;
    
    for (int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
        sum1 += queue1[i];
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    int cnt = 0;
    while(cnt <= count){
        if (sum1 == sum2) return cnt;
        if (sum1 < sum2){
            long long tmp = q2.front();
            q1.push(tmp);
            q2.pop();
            sum1 += tmp;
            sum2 -= tmp;
            
        }
        else{
            long long tmp = q1.front();
            q2.push(tmp);
            q1.pop();            
            sum2 += tmp;
            sum1 -= tmp;
        }
        cnt++;
    }
    return -1;
    
}