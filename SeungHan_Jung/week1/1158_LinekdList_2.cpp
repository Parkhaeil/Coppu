// 계속 pop 하되 완전히 버리면 안 되는 인자는 다시 뒤로 넣는 queue 를 이용하는 구현 방법

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    
    queue<int> Q;
    for(int i = 1 ; i <= n ; i++){
        Q.push(i);
    }
    cout << '<';
    while(!Q.empty()){
        for(int i = 0 ; i < k - 1 ; i++){ // 여기 계속 k 라고 했다가 여러번 틀림
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if(Q.size()) cout << ", ";
    }
    cout << '>'; 
}
