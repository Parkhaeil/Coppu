#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;
#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int t;
    cin >> t;
    while(t>0) {
        int board[51][51]={0};
        bool visited[51][51]={0};
        int m,n,k;
        cin >> m >> n >> k;
        for (int i=0;i<k;i++) {
            int x,y;
            cin >> x >> y;
            board[y][x]=1;
        }
        queue<pair<int,int>> q;
        int num=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (!visited[i][j] && board[i][j]==1) {
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for (int dir=0;dir<4;dir++) {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if (nx<0||nx>=n||ny<0||ny>=m) continue;
                            if (visited[nx][ny] || board[nx][ny]==0) continue;
                            q.push({nx,ny});
                            visited[nx][ny]=true;
                        }
                    }
                    num++;
                }
            }
        }
        cout << num << '\n';
        t--;
    }

}
