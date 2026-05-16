#include <string>
#include <vector>
#include <iostream>

using namespace std;
int total_numbers;
int answer = 0;
int final_target = 0;

// 탐색이긴 한데 그냥 완전 탐색 처럼 갔다가는 연산량이 말도 안 되게 커질거임
// 게다가 반복되는 계산들이 있음 -> 이거 뭔가 dp 의 향기가 찐하게 난다.
// 우리는 dfs 와 dp 이 두 가지 방법 모두를 이용해서 풀어보자

// sol1. by dfs : 누적상태 , 새롭게 시도해 볼 상태 , 재귀호출 또는 stack
// void dfs(vector<int> numbers,int index,int cur){
//     // 종료조건들 세팅
//     if(index == total_numbers){
//         if(cur ==  final_target) {
//             answer ++;
//         }
//         return ; 
//     }    
//     // 현재 꺼를 - 붙여서 더하는 경우 -> 누적상태 + 재귀호출
//     dfs(numbers, index + 1 , cur + (-1)*numbers[index]);
//     // 현재 꺼를 + 붙여서 더하는 경우 -> 누적상태 + 재귀호출
//     dfs(numbers, index + 1 , cur + numbers[index]);
// }

// int solution(vector<int> numbers, int target) {
//     total_numbers = numbers.size();
//     final_target = target;
//     dfs(numbers,0,0);
//     return answer;
// }

// sol2. 반복되는 계산이 너무 많다 -> 난 꼭 dp 를 쓰고 싶다 : 계산이 어떤 패턴으로 반복되고 있는지를 먼저 찾아야 한다.
// 0:0
// 1:-4 4
// 2:-1-4 , -1+4 , 1-4 , 1+4 
// 3:-7 -5 1 3 -3 -1 5 7

int solution(vector<int> numbers, int target) {
    vector<vector<int>> dp;
    total_numbers = numbers.size();
    final_target = target;
    vector<int> temp;
    for(int i = 0 ; i < numbers.size() ; i++){
        if(i==0){
            vector<int> temp;
            temp.push_back((-1)*numbers[0]);
            temp.push_back(numbers[0]);
            // for(int i = 0 ; i < temp.size() ; i++){
            //     cout << temp[i] << " ";
            // }
            // cout << "\n";
            dp.push_back(temp);
            continue;
        }
        for(int j = 0 ; j < dp[i-1].size() ; j++){
            temp.push_back((-1)*numbers[i] + dp[i-1][j]);
            temp.push_back(numbers[i] + dp[i-1][j]);
        }
        // for(int i = 0 ; i < temp.size() ; i++){
        //     cout << temp[i] << " ";
        // }
        // cout << "\n";
        dp.push_back(temp);
        temp.clear();
    }
    int last_row = int(dp.size()) -1;
    for(int i = 0 ; i < dp[last_row].size() ; i++){
        if(dp[last_row][i] == target) answer++;
    }
    return answer;
}
