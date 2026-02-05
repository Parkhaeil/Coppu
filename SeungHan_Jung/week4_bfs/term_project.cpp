#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int state[100005]; 
int n;

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

    // 이 함수에 들어왔다는 것은 아직 state[x] 의 값이 cycle_in 이 아닌 0 이라는 말이고
    // 시작점에서 쭉쭉 arrow 타고 가다가 한번이라도  state의 값이 이미 cycle_in 이면 포기하고 나옴    
 void run(int x){
        int cur = x;
        while(true){
            state[cur] = x;
            cur = arr[cur];
            if(state[cur] == x){ // 루프가 완성 되었을떄 -> 이제 state 의 값을 모두 -1로 change
                while(state[cur] != CYCLE_IN){
                    state[cur] = CYCLE_IN;
                    cur = arr[cur];
                }
                return;
            }
            else if(state[cur] != 0) return;
        } // 그니까 루프 완성될때까지 계속 돌리는거야 -> dfs?
    }

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i = 1 ; i <=n ; i++){
            cin >> arr[i]; // 각 학생이 어떤 학생을 지목했는지.
        }
        fill(state+1,state+n+1,0);
        for(int i = 1 ; i <= n ; i++){
            if(state[i] == NOT_VISITED) run(i);
            // 루프가 확실하게 형성이 되었을때만 state 에 cycle_in 값을 박는다.
            // 만약 어떤 노드든 자기는 가르키고 있는데 다른 애랑 루프가 형성이 되어서
            // state 에 cycle_in 값이 딱 설정이 되어 있으면,
            // 그건 실행 안 함. 어차피 안될거 아니까
        }
        int cnt = 0;
        for(int i = 1 ; i <= n;i++){
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
