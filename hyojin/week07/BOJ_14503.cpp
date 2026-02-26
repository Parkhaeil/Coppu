#include<iostream>
using namespace std;
int board[51][51];
// d=0 북 , d=1 동, d=2 남, d=3 서
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


int main() {
    int n,m;
    cin >> n >> m;
    int r,c,d;
    cin >> r >> c >> d;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            // 청소x=0 , 벽=1
            cin >> board[i][j];
        }
    }
    int cnt=0;
    while(true) {
        // 현재 칸 청소
        if (board[r][c]==0) {
            board[r][c]=2;
            cnt++;
        }
        bool flag=false;
        // 현재 칸의 주변 4칸 탐색
        // => 빈칸 있는지 먼저 체크 후 이동로직
        for (int dir=0;dir<4;dir++) {
            int nx=r+dx[dir];
            int ny=c+dy[dir];
            if (nx<0||nx>=n||ny<0||ny>=m) continue;
            // 청소되지 않은 빈 칸
            if (board[nx][ny]==0) {
                flag=true;
                break;
            }
        }
        // 청소되지 않은 빈 칸이 있는 경우
        if (flag) {
            // 반시계 90도 회전
            d=(d+3)%4;
            int nx=r+dx[d];
            int ny=c+dy[d];
            if (board[nx][ny]==0) {
                r=nx; c=ny;
            }
        } // 청소되지 않은 빈 칸이 없는 경우
        else {
            int nx=r-dx[d];
            int ny=c-dy[d];
            if (board[nx][ny]==1) {
                cout << cnt;
                return 0;
            }
            r=nx; c=ny;
        }
    }
}