// 여러개의 고려 대상이 있는 것 같을때 그 중 바로 전거나 가장 높은 거 하나 빼고는 영향을 못 미치는 경우!
// 앞의 데이터를 다 가지고 있는게 아니라 더 이상 영향 미치지 목하는 데이터를 다 버린다는 그 사고!
// 가 중요한 듯

#include <bits/stdc++.h>
using namespace std;

stack<pair<int , int>> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); // 이거 없으니까 진짜 안 되네? ㅋ
    int num,counter;
    cin >> num;
    counter = 0;
    
    s.push({1000000001 , 0});
    
    for(int i  = 0 ; i < num ; i++){
        int height;
        cin >> height;
        counter += 1;
        
        while(s.top().first < height){
            s.pop();
        } 
        // 죽일놈의 if 쓸지 while 쓸지 , if / while 조건문 속 부등호의 방향
        // 근데 웬만한 메인 로직에서는 아무래도 while 문이 더 많이 쓰이는 듯
        cout << s.top().second << " ";
        s.push({height,counter});
}
}
