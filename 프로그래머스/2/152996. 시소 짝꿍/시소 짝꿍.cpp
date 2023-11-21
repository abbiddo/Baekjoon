#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long arr[1001];

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for (int i : weights) arr[i]++;
    
    for (int i = 100; i <= 1000; i++){
        if (arr[i]){
            if (arr[i] > 1) answer += (arr[i] * (arr[i] - 1))/2;
            cout<<answer<<" ";
            if (i * 2 < 1001 && arr[i * 2]) answer += arr[i*2] * arr[i];
            cout<<answer<<" ";
            if (i % 2 == 0 && i/2*3 < 1001) answer += arr[i/2*3] * arr[i];
            cout<<answer<<" ";
            if (i % 3 == 0 && i/3*4 < 1001) answer += arr[i/3*4] * arr[i];     
            cout<<answer<<"\n";
        }
    }
    
    return answer;
}