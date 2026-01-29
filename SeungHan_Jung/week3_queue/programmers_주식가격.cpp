#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        // 스택이 비지 않았고, 현재 가격이 스택 top의 가격보다 작다면 (가격 하락)
        while (!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    // 스택에 남은 요소들(가격이 끝까지 떨어지지 않은 경우) 처리
    while (!s.empty()) {
        answer[s.top()] = n - 1 - s.top();
        s.pop();
    }

    return answer;
}


// #include <string>
// #include <vector>
// #include <queue>
// #include <iostream>

// using namespace std;

// vector<int> solution(vector<int> prices) {
//     vector<int> out;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     // first 가 작을 수록 , first 가 같다면 뒤의 인자가 작을 수록 먼저 나옴.
    
//     for(int i = 0 ; i < prices.size() ; i++){
//         q.push({prices[i] , i});
//     }
    
// //     """
// //     pair<T1, T2>를 기본 비교로 쓰는 한
// // 👉 첫 번째(first)를 먼저 비교
// // 👉 같으면 두 번째(second)를 비교
// //     이건 항상이다.    
// //     """    
        
//     auto minimum_price = -1; 
//     auto current = q.top().second;
//     prices[current] = prices.size() - current - 1; 
        
//     while(1){
//         current = q.top().second;
//         q.pop();
//         out.push_back(current);
//         if(q.empty()) return prices;
//         auto next = q.top().second;
//         //cout << next << "\n";
//         // if(next < current){
//         //     prices[next] =  current - next ;
//         // }else{
//         //     prices[next] = prices.size() - next - 1;
//         // }
//         int minus = 100008; 
//         for(int m : out){
//             if(m > next){
//                 int value = m-next;
//                 if( value < minus) minus = value;
//             }else{
//                continue;
//            }
//         }
//         if(minus == 100008){
//             minus = prices.size() - next - 1;
//         }
//         prices[next] =  minus ;
        
        
//     }
    
//     return prices;
// }
