// 덱의 시작과 끝을 나타내는 "포인터(찐 메모리 주소)" : front() , back()
// 포인터가 아닌 iterator 는 d.begin(),d.end() 이다.
// push_front/back , pop_front/back 은 이런게 왜 생긴지 직관적으로 이해가 가능.
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m;
    cin >> n ; 
    cin >> m;
    
    deque<int> d;
    for(int i = 1 ; i <= n ; i++){ // 하 여기가 0부터 넣기 시작해서 n 찾는다고 계속 무한루프 돌았다..
        d.push_back(i);
    }
    int ans = 0;
    while(m--){
        int t = 0 ;
        cin >> t;
        int idx = find(d.begin(),d.end(),t) - d.begin(); 
        // find 함수 사용시 우리가 지정한 첫 iterator부터 마지막 iterator까지 돌면서
        // 우리가 찾아달라고 한 그 값이 있는 iterator 값을 반환 , iterator 간의 뺄셈 연산은
        // 미리 std::find(iterator,iterator,value) 는 그 내부에 - 연산자를 오버로딩 해 놨기에
        // - 연산의 결과는 그냥 정수형이 된다.
        
        while(d.front() != t){
            if(idx < d.size() - idx){
                d.push_back(d.front());
                d.pop_front();
            }else{
                d.push_front(d.back());
                d.pop_back();
            }
            ans++;
        }
        d.pop_front();
    }
    
    cout << ans;
    
}
