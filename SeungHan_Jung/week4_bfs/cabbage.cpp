// 하 좌표 쌰갈 겁나 헷갈리네

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51];
int d_x[4] = {1,0,-1,0};
int d_y[4] = {0,1,0,-1};
int w,h;

queue<pair<int,int>> q;

void bfs(int m , int n){ // m 이 세로의 좌표 , n 이 가로의 좌표 -> 
    // (2 1) 로 들어온 입력이 밑에서 이미 1,2로 바뀌어서 들어온거임
    q.push({m,n});
    while(!q.empty()){
        auto current = q.front(); q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int ny = current.X + d_y[i]; // 그냥 인덱스로 -> 이게 가로축임
            int nx = current.Y + d_x[i];
            
            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            // 인덱스 = 개수 - 1 !!
            if(board[ny][nx] != 1 || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny,nx});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,res;
    cin >> t;
    while(t--){
        int p; // 너비 , 높이 , 그 격자에서 1인 격자의 개수
        cin >> w >> h >> p; // w 가 가로축 , h 가 세로축
        res = 0;
        int x,y;
        for(int i = 0 ; i < p ; i++){
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        for(int m = 0 ; m < h ; m++){
            for(int n = 0 ; n < w ; n++){
                if(board[m][n] == 1 && !vis[m][n]){
                    vis[m][n] = true;
                    bfs(m,n);
                    res++   ;
                }
            }
        }
        
        cout << res << "\n";
        for(int i = 0; i < h; i++){
             fill(board[i], board[i]+w, 0);
             fill(vis[i], vis[i]+w, false);
        }
    }
    return 0;
}
    
