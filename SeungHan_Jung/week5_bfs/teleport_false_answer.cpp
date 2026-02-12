#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    if(n == m){
            cout << 0;
            return 0;
        }
    
    // 특정 시작점이 있을떄 , 무조건 그 2배인 순간이동을 한 그 결과 위치가 비용이 0이기에
    // 그것들이 반드시 먼저 체크가 되어야 함. 그리고 그 순간이동 위치가 -1,+1 한 그 위치들은 
    // 덱의 뒤로 가야 자연스럽게 , 먼저 pop 되는 좌표 시작점이 반드시 아직 남아있는 것들에 비해
    // 더 적은 비용으로 해당 위치에 있다는게 딱 전제 수립이 됨
    // bfs 의 밑바탕 : 
    // 1. 큐나 덱에서 먼저 pop 되는 아이가 이후에 pop 되는 아이들보다 더 적거나 같은 비용으로
    // 2. 누구도 visit 한 적 없는 특정 위치에 처음 방문해야 한다
    // 3. 1~2 의 전제가 성립 된 제대로된 bfs 라면 , 특정 그 위치가 타깃 위치일때 가장 먼저 방문해졌을 떄의 그 비용이 최소의 비용이다.
    
    deque<pair<int,int>> d; // 비용
    d.push_front({0,n});
    bool dist[100003] = {false};
    dist[n] = true; // 제발
    
    while(!d.empty()){
        auto cur = d.front(); d.pop_front();
        int bill = cur.first;
        int x = cur.second;
        int nx;
        
        // 덱의 앞에 넣어야 하는 것
        nx = 2*x;
        if(nx <= MAX && !dist[nx]){
            //cout << "nx : " << nx << "m : " << m << "\n";
            if(nx == m) {
                cout << bill;
                return 0;
            }
            //cout << "first" << "\n";
            d.push_front({bill,nx});
            dist[nx] = true;
        }
            ㄹ
        // 덱의 뒤에 넣어야 하는 것
        
        nx = x - 1;
        if(nx >= 0 && !dist[nx]){
            //cout << "nx : " << nx << "m : " << m << "\n";
            if(nx == m) {
                cout << bill + 1;
                return 0;
            }
            //cout << "second" << "\n";
            d.push_back({bill + 1,nx});
            dist[nx] = true;
        }
        
        nx = x + 1;
        if(nx <= MAX && !dist[nx]){
            //cout << "nx : " << nx << "m : " << m << "\n";
            if(nx == m) {
                if(nx == 2){ // 미친 진짜 이것 때문이었네.
                    cout << bill;
                }else{
                    cout << bill + 1;
                }
                return 0;
            }
            //cout << "third" << "\n";
            d.push_back({bill + 1,nx});
            dist[nx] = true;
        }
        
        // 예외가 가능한 경우 -> 1,2 : 2베를 통해서 순간이동할 수 있는데 +1로 더 비용싼 경우면 틀림
        
    }
    
}
