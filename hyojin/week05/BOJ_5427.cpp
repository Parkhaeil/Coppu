#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int person[1001][1001];
int fire[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int w,h;
        cin >> w >> h;
        string board[1001];
        for (int i=0;i<h;i++) {
            cin >> board[i];
        }
        // 초기화
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                person[i][j]=-1;
                fire[i][j]=-1;
            }
        }
        // 불 시작점들 찾아서 BFS
        queue<pair<int,int>> q1;
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                if (board[i][j]=='*') {
                    fire[i][j]=0;
                    q1.push({i,j});
                }
            }
        }
        while(!q1.empty()) {
            auto cur=q1.front(); q1.pop();
            for (int dir=0;dir<4;dir++) {
                int nx=cur.X+dx[dir];
                int ny=cur.Y+dy[dir];
                if (nx<0||nx>=h||ny<0||ny>=w) continue;
                // 이미 방문헀거나 벽일때 패스
                if (fire[nx][ny]!=-1 || board[nx][ny]=='#') continue;
                fire[nx][ny]=fire[cur.X][cur.Y]+1;
                q1.push({nx,ny});
            }
        }
        // 상근이 찾아서 BFS
        queue<pair<int,int>> q2;
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                if (board[i][j]=='@') {
                    person[i][j]=0;
                    q2.push({i,j});
                }
            }
        }
        // 탈출 성공 플래그
        bool flag=false;
        // 탈출 플래그도 while문에 넣어주기!!
        while(!q2.empty() && !flag) {
            auto cur=q2.front(); q2.pop();
            for (int dir=0;dir<4;dir++) {
                int nx=cur.X+dx[dir];
                int ny=cur.Y+dy[dir];
                // 범위 넘어서 탈출 성공했는지
                if (nx<0||nx>=h||ny<0||ny>=w) {
                    flag=true;
                    cout << person[cur.X][cur.Y]+1 << '\n';
                    break;
                }
                // 이미 방문헀거나 벽일때 패스
                if (person[nx][ny]!=-1 || board[nx][ny]=='#') continue;
                // 불 붙었거나 붙을 예정일 때 패스
                if (fire[nx][ny]<=person[cur.X][cur.Y]+1 &&
                    fire[nx][ny]!=-1) continue;
                person[nx][ny]=person[cur.X][cur.Y]+1;
                q2.push({nx,ny});
            }
        }
        if (!flag) cout << "IMPOSSIBLE" << '\n';
    }
}