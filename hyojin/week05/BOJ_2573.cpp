#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int n,m;
int board[301][301];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>> q;
bool visited[301][301];

// 빙하 개수 BFS
void icebugNumBFS() {
    while(!q.empty()) {
        auto cur=q.front(); q.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (board[nx][ny]==0 || visited[nx][ny]) continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
    }
}

// 빙하 높이 깎기
// => 얼마나 깎아야하는지 계산 후 한번에 깎기
void melt() {
    int seaNum[301][301]={0};
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (board[i][j]==0) continue;
            for (int dir=0;dir<4;dir++) {
                int nx=i+dx[dir];
                int ny=j+dy[dir];
                if (nx<0||nx>=n||ny<0||ny>=m) continue;
                if (board[nx][ny]==0) seaNum[i][j]++;
            }
        }
    }
    // => 음수 될수도 있으니 max로 처리해야함
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            board[i][j]=max(0,board[i][j]-seaNum[i][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    int year=0;
    // 빙산이 분리되거나 없어질때까지 
    while(true) {
        // => visited 매년 초기화해야함
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                visited[i][j]=false;
            }
        }
        // 빙산 개수 BFS
        int icebugNum=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (board[i][j]!=0 && !visited[i][j]) {
                    q.push({i,j});
                    visited[i][j]=true;
                    icebugNumBFS();
                    icebugNum++;
                }
            }
        }
        // 빙산 분리됬을 때
        if (icebugNum>=2) {
            cout << year;
            break;
        } 
        // 다 녹을 때까지 분리되지 않을때
        else if (icebugNum==0) {
            cout << "0";
            break;
        }
        // 빙하 녹이기
        melt();
        year++;
    }
}