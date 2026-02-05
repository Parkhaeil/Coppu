#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[1001];
int dist[1001][1001][2];
/*
BFS는 미래를 고려한 선택을 하면 안 됨
조건 분기 + 선택 로직x
*/

// 상태를 3차원으로 만든다
// dist[x][y][wall]
// wall = 0 → 아직 벽 안 부숨
// wall = 1 → 이미 벽 부숨
// 큐에 넣는 것도
// queue<tuple<int,int,int>> q; <- x, y, wall

int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    dist[0][0][0]=1;
    while(!q.empty()) {
        auto [x,y,wall]=q.front(); q.pop();
        if (x==n-1 && y==m-1) {
            cout << dist[x][y][wall];
            return 0;
        }
        for (int dir=0;dir<4;dir++) {
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            // 벽 있고 부수기 가능할 때
            if (board[nx][ny]=='1'&&wall==0&&dist[nx][ny][1]==-1) {
                dist[nx][ny][1]=dist[x][y][wall]+1;
                q.push({nx,ny,1});
            }
            // board[nx][ny]=0으로 벽 안 부수고 갈수 있을때
            if (board[nx][ny]=='0'&&dist[nx][ny][wall]==-1) {
                q.push({nx,ny,wall});
                dist[nx][ny][wall]=dist[x][y][wall]+1;
            }
        }
    }
    cout << -1;
}
