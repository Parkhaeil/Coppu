/*
말 이동 횟수를 3차원으로
기회/횟수를 하나의 차원으로 만들기!!!!제발
*/

#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
#define X first
#define Y second
int k,w,h;
int board[201][201];
int dist[201][201][31];
int dxH[8]={-2,-2,-1,1,-1,1,2,2};
int dyH[8]={-1,1,-2,-2,2,2,-1,1};
int dxM[4]={1,0,-1,0};
int dyM[4]={0,1,0,-1};
queue<tuple<int, int, int>> q;

int main() {
    cin >> k;
    cin >> w >> h;
    for (int y=0;y<h;y++) {
        for (int x=0;x<w;x++) {
            cin >> board[y][x];
        }
    }
    
    q.push({0,0,0});
    dist[0][0][0]=1;
    while(!q.empty()) {
        int curx, cury, curk;
        tie(curx, cury, curk) = q.front();
        q.pop();
        // 말 이동 k 번 다 안 썼을 때
        if (curk < k) {
            // 말 이동
            for (int dir=0;dir<8;dir++) {
                int nx=curx+dxH[dir];
                int ny=cury+dyH[dir];
                if (nx<0||nx>=w||ny<0||ny>=h) continue;
                if (dist[ny][nx][curk+1] || board[ny][nx]==1) continue;
                dist[ny][nx][curk+1]=dist[cury][curx][curk]+1;
                q.push({nx,ny,curk+1});
            }
        }
        for (int dir=0;dir<4;dir++) {
            int nx=curx+dxM[dir];
            int ny=cury+dyM[dir];
            if (nx<0||nx>=w||ny<0||ny>=h) continue;
            if (dist[ny][nx][curk] || board[ny][nx]==1) continue;
            dist[ny][nx][curk]=dist[cury][curx][curk]+1;
            q.push({nx,ny,curk});
        }
    }
    int mn=0x7f7f7f7f;
    for (int i=0;i<k+1;i++) {
        if (dist[h-1][w-1][i]!=0) mn=min(mn, dist[h-1][w-1][i]);
    }
    if (mn != 0x7f7f7f7f) cout << mn - 1;
    else cout << -1;
}