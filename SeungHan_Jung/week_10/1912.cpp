// 핵심은 누적적으로 쌓아가다가 음수가 나왔다면 바로 다 버려버려야함!

#include <bits/stdc++.h>
using namespace std;

int a[100003] = {0,};
int T;

int main(void){ 
    int N;
    cin >> N;
    
    std::vector<int> v;
    
    for(int i = 0 ; i < N ; i++){
        cin >> T;
        v.push_back(T);
    }
    
    a[0] = v[0];
    
    for(int i = 1 ; i < N ; i++){
        a[i] = max(a[i-1],0) + v[i];
    }
    
    cout << *max_element(a,a+N);
    // max_element(a,a+N-1) 했다가 틀렸는데 이떄는 N=1일떄가 문제가 아니라(이건 정상적으로 출력되니까)
    // n이 일반적인 수일떄 , 마지막의 값이 정답으로 이어지는 아주 큰 수인 경우 틀리게 되는거임!
}
