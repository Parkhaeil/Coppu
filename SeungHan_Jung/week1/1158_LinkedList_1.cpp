// 연결리스트를 prev 와 nxt 를 각각 수동 포인트로 설정해서 두개의 배열로 구현하는 레전드 노가다 기

#include<bits/stdc++.h>
using namespace std;

int N,K,len = 0;

int pre[5001]; // 직관적으로 1부터 쓸려고 5001 이라고 한 것 -> 0번째 인덱스 안 쓸거임
int nxt[5001];

vector<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    
    for(int i = 1 ; i <= N ; i++){
        pre[i] = (i==1) ? N : i-1;
        nxt[i] = (i==N) ? 1 : i+1;
        len++;
    }
    
    int i = 1;
    for(int cur = 1 ; len != 0 ; cur = nxt[cur]){
        if(i == K){
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            v.push_back(cur);
            i = 1;
            --len;
        }else ++i;
    }
    
    cout << "<";
    for(size_t i = 0 ; i < v.size() ; ++i){
        cout << v[i];
        if(i != v.size() -1) cout << ", ";
    }
    cout << ">";
}
