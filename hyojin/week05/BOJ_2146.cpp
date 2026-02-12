/*
bfs를 2번만 사용해 O(n^2) 문제를 풀어내는 풀이는

void island() -> BFS로 board를 섬의 번호로 갱신
int main()->
    1. board가 섬인 곳의 dist를 모두 0으로 갱신하고 큐에 넣기
    2. BFS로 인접한 곳이 다른 섬일 때
        ans = min(ans,dist[nx][ny]+dist[cur.X][cur.Y]); 로
        cur와 (nx, ny) 각각이 육지로부터 떨어진 거리를 합하면 된다.
*/

#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define X first
#define Y second
int n;
int mn=9999;
int board[101][101];
bool visited[101][101];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int tempBoard[101][101];
bool tempVisited[101][101];

void BFS(int x, int y) {
    // 임시 저장 배열들 초기화
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            tempBoard[i][j]=-1;
            tempVisited[i][j]=false;
        }
    }
    visited[x][y] = true;

    // tempBoard[x][y]=0으로 현재 섬의 육지인거 표시
    // & tempvisited=true 로 방문 표시
    queue<pair<int,int>> q1;
    // q2에 현재 섬 육지 다 넣기
    queue<pair<int,int>> q2;

    q1.push({x,y});
    tempBoard[x][y] = 0;
    tempVisited[x][y] = true;
    q2.push({x, y});
    while(!q1.empty()) {
        auto cur=q1.front(); q1.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (board[nx][ny]==0 || visited[nx][ny]) continue;
            visited[nx][ny]=true;
            tempBoard[nx][ny]=0;
            tempVisited[nx][ny]=true;
            q1.push({nx,ny});
            q2.push({nx,ny});
        }
    }
    // 거리 구하기
    while(!q2.empty()) {
        auto cur=q2.front(); q2.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=n) continue;
            if (tempVisited[nx][ny]) continue;
            // 다른 섬 도달했을때 최소 거리인지 확인
            if (board[nx][ny]==1 && tempBoard[nx][ny]==-1) {
                mn=min(mn,tempBoard[cur.X][cur.Y]);
            }
            tempBoard[nx][ny]=tempBoard[cur.X][cur.Y]+1;
            tempVisited[nx][ny]=true;
            q2.push({nx,ny});
        }
    }
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (!visited[i][j] && board[i][j]==1) {
                BFS(i,j);
            }
        }
    }
    cout << mn;
}

