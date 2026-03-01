/*
벽 세울 때 가능한 모든 경우 탐색해야하므로 백트래킹 사용하기

백트래킹에서 중복 없게 하려면 
빈칸의 위치만 따로 vector에 모아서 계산하면 됨
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int board[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second
int n,m;
int mx=0;

void BFS() {
    // => 원본 보존해야함
    int temp[9][9];
    queue<pair<int,int>> q;
    // => 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = board[i][j];
            if (temp[i][j] == 2) q.push({i, j});
        }
    }
    while (!q.empty()) {
        auto cur=q.front(); q.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            if (temp[nx][ny]!=0) continue;
            temp[nx][ny]=2;
            q.push({nx,ny});
        }
    }
    int sum=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (temp[i][j]==0) {
                sum++;
            }
        }
    }
    mx=max(mx,sum);
}

//=> 벽 백트래킹으로 3개 세우기
void wall(int depth) {
    if (depth==3) {
        BFS();
        return;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (board[i][j]==0) {
                board[i][j]=1;
                wall(depth+1);
                board[i][j]=0;
            }
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
    wall(0);
    cout << mx;
}