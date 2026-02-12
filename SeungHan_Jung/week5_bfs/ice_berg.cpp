#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300][300]; // 현재 바다의 상태
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m; // n 이 행 수 , m 이 열 수임.
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    
    int ans = 0;
    while(1){
        int block = 0;
        bool d[300][300] = {}; // 매번 모두 false 초기화
        // 1) 빙산 덩어리 수 세기
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j] != 0 && !d[i][j]){ // a[i][j] > 0 이랑 같은 의미
                    block ++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    d[i][j] = true;
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];
                            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 제발
                            if(a[ny][nx] > 0 && !d[ny][nx]){
                            d[ny][nx] = true;
                            q.push({ny,nx});
                            }
                            // 위와 같은 화이트 리스트 보다는 항상 밑과 같은 블랙리스트 코드가 더 안전한 것 같긴함.
                            // if(a[ny][nx] == 0 || d[ny][nx]) continue;
                            // d[ny][nx] = true;
                            // q.push({ny,nx});
                    }
                }
                
            }
        }
        }
        if(block > 1){
            cout << ans;
            return 0;
        }else if(block == 0){
            // 계속 ans 를 늘리면서 기다렸는데 , 갑자기 어느 순간 한번에 다 사라짐
            // 다 같이 침몰
            cout << 0;
            return 0;
        }
        
        int next[300][300];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                next[i][j] = a[i][j];
        
        // 이제 바닷물에 따라서 그 a 라는 배열에서 
        // 값이 0보다 큰 칸의 값을 주위에 바다가 몇개인지에 따라 줄일 차례 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j] > 0){ // 실시간 아님 -> 변하지 않은 원본을 기준으로 next 는 결과 반영만
                    for(int k = 0 ; k < 4 ; k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if(a[ny][nx] == 0 && next[i][j] -1 >=0){
                            // d 의 값이 true 곧 바다이면서 && 그 바다의 영향으로 a 의 값을 빼도 문제가 안 생겨야함.
                            // a 는 쓰면 안 됨 . 현재 실시간으로 업데이트 되고 있어서
                            // 실시간 흐름이면 a 를 썼어야겠지만
                            next[i][j] -= 1;
                        } // 이건 근데 또 블랙리스트 코드 보다는 바로 위와 같은 화이트 리스트 코드가 더 나은 것 같고
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = next[i][j];
        
        ans++;
        
    } 
}
