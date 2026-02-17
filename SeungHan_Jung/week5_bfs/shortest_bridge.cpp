#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
int owner[105][105];
int dista[105][105];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    // 섬 라벨링
    int id = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                id++;
                queue<pair<int,int>> q;
                q.push({i,j});
                a[i][j] = id;

                while(!q.empty()){
                    auto [y,x] = q.front(); q.pop();
                    for(int d = 0; d < 4; d++){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(a[ny][nx] != 1) continue;
                        a[ny][nx] = id;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }

    // owner / dist 초기화 (for문)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            owner[i][j] = 0;
            dista[i][j] = -1;
        }
    }

    // 멀티 소스 BFS 시작
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] > 0){
                owner[i][j] = a[i][j];
                dista[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    int ans = 1e9;

    while(!q.empty()){
        auto [y,x] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            // 아직 아무 섬도 안 먹은 바다
            if(a[ny][nx] == 0 && owner[ny][nx] == 0){
                owner[ny][nx] = owner[y][x];
                dista[ny][nx] = dista[y][x] + 1;
                q.push({ny,nx});
            }
            // 다른 섬이 이미 먹은 곳
            else if(owner[ny][nx] != 0 && owner[ny][nx] != owner[y][x]){
                // ans = dista[ny][nx] + dista[y][x];
                // cout << ans;
                // return 0; ㅁㅊ 안 되는 이유를 알아버렸음
                // A 0 0 B
                // A 0 0 0 C -> c 가 먼저 감지가 됨 : 멀티소스 bfs 의 한계.

                ans = min(ans, dista[ny][nx] + dista[y][x]);
            }
        }
    }

    cout << ans;
    return 0;
}
