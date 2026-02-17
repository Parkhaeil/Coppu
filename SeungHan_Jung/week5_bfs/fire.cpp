#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int fire[1003][1003];
int dist[1003][1003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c,r,cr,cc;
    cin >> n;
    while(n--){
        cin >> c >> r;
        
        // 배열 초기화
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                fire[i][j] = -1;
                dist[i][j] = -1;
            }
        }
        
        vector<string> board(r);
        for(int j = 0 ; j < r ; j++){
            cin >> board[j];
        }
        
        queue<pair<int,int>> fq; // 불
        queue<pair<int,int>> q;  // 사람
        
        // 초기 위치들 세팅
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == '*') {
                    fq.push({i, j});
                    fire[i][j] = 0;
                }
                if (board[i][j] == '@') {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // 1. 불 bfs
        while(!fq.empty()){
            auto cur= fq.front(); fq.pop();
            int y = cur.first, x = cur.second;
            for(int d = 0 ; d < 4 ; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if(board[ny][nx] == '#') continue;
                if(fire[ny][nx] != -1) continue;
                fire[ny][nx] = fire[y][x] + 1;
                fq.push({ny,nx});
            }
        }
        
        // 2. 이동 bfs
        int ans = -1;
        while(!q.empty()){
            // 1. 기본세팅
            cr = q.front().first;
            cc = q.front().second;
            q.pop();
            
            int nt = dist[cr][cc] + 1;
            // 3. 이제 사용자의 위치를 옮기면서 가능한지 체크
            for(int m = 0; m < 4 ; m++){
                        int nr = cr + dy[m];
                        int nc = cc + dx[m];
                        // 가장자리인데 살아 남았다? 바로 정답
                        if(nr < 0 || nr >= r || nc < 0 || nc >= c){
                            ans = nt;
                            while(!q.empty()) q.pop();
                            break;
                        }
                        // 벽이다? 패스
                        if(board[nr][nc] == '#') continue;
                        // 가장 자리도 아니고 벽도 아니라서 이동을 할 수 있는 경우
                        // 일단 내가 방문한 적은 적어도 없어야 함. 그리고
                        // 분명 그 자리는 불이 언젠가는 있을거임, 단 내가 도착하는 그 시점보다 더 나중에 불이 생기는지의 차이
                        // 이 두가지를 만족을 하면 내가 들렀다 갈 위치이다 라는 조건을 만족
                        if(dist[nr][nc] == -1 && (fire[nr][nc] > nt || fire[nr][nc] == -1)){
                            dist[nr][nc] = nt;
                            q.push({nr,nc});
                        }
               }  
        }
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}
