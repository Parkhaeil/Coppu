// 아니 시간 복잡도가 높은 포인트도 딱히 없는데 , 시간 초과가 왜 뜨지 했는데
// endl이 유발하는 줄바꿈 flush 떄문인 것 같음
// 이런 사고 한번 계속 상기할만해

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int cnt = 1;
    cin >> n;
    stack<int> S;
    string ans = {};
    while(n--){
        int t;
        cin >> t;
        while(cnt <= t){
            S.push(cnt++);
            ans+="+\n" ;
        }
        if(t==S.top()){
            ans+="-\n";
            S.pop();
        }else{
            cout << "NO\n" ;
            return 0;
        }
    }
    cout << ans;
}
