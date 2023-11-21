#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[24][60];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for (int i = 0; i < book_time.size(); i++){
        int sh = stoi(book_time[i][0].substr(0, 2));
        int eh = stoi(book_time[i][1].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int em = stoi(book_time[i][1].substr(3, 2));
        
        if (em < 50) em += 9;
        else {
            if (eh == 23) em = 59;
            else{
                eh++;
                em = em - 51;
            }
        }
        
        if (sh == eh){
            for (int m = sm; m <= em; m++) arr[sh][m]++;
        }
        else{
            for (int m = sm; m <= 59; m++) arr[sh][m]++;
            for (int h = sh + 1; h < eh; h++){
                for (int m = 0; m <= 59; m++) arr[h][m]++;
            }
            for (int m = 0; m <= em; m++) arr[eh][m]++;
        }
        
        /*if (em + 9 < 60){
            for (int m = em; m < em + 10; m++) arr[sh][m]++;
        }
        else {
            for (int m = em; m < 60; m++) arr[sh][m]++;
            if (sh != 23) for (int m = 0; m < em - 50; m++) arr[sh+1][m]++;
        }*/
    }
    
    for (int i = 0; i < 24; i++){
        for (int j = 0; j < 60; j++){
            answer = max(answer, arr[i][j]);
        }
    }
    
    return answer;
}