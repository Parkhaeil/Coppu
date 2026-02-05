#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;
#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[101];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> board[i];
    }
    // 색약x
    int num1=0;
    queue<pair<int,int>> q1;
    bool visited1[101][101]={0};

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (!visited1[i][j] && board[i][j]=='R') {
                    q1.push({i,j});
                    visited1[i][j]=true;
                    while(!q1.empty()) {
                        auto cur=q1.front(); q1.pop();
                        for (int dir=0;dir<4;dir++) {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if (nx<0||nx>=n||ny<0||ny>=n) continue;
                            if (visited1[nx][ny] || board[nx][ny]!='R') continue;
                            q1.push({nx,ny});
                            visited1[nx][ny]=true;
                        }
                    }
                    num1++;
                }
            if (!visited1[i][j] && board[i][j]=='G') {
                    q1.push({i,j});
                    visited1[i][j]=true;
                    while(!q1.empty()) {
                        auto cur=q1.front(); q1.pop();
                        for (int dir=0;dir<4;dir++) {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if (nx<0||nx>=n||ny<0||ny>=n) continue;
                            if (visited1[nx][ny] || board[nx][ny]!='G') continue;
                            q1.push({nx,ny});
                            visited1[nx][ny]=true;
                        }
                    }
                    num1++;
                }
            if (!visited1[i][j] && board[i][j]=='B') {
                    q1.push({i,j});
                    visited1[i][j]=true;
                    while(!q1.empty()) {
                        auto cur=q1.front(); q1.pop();
                        for (int dir=0;dir<4;dir++) {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if (nx<0||nx>=n||ny<0||ny>=n) continue;
                            if (visited1[nx][ny] || board[nx][ny]!='B') continue;
                            q1.push({nx,ny});
                            visited1[nx][ny]=true;
                        }
                    }
                    num1++;
                }
        }
    }
    // 색약 0
    int num2=0;
    queue<pair<int,int>> q2;
    bool visited2[101][101]={0};

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (!visited2[i][j] &&
                (board[i][j]=='R' || board[i][j]=='G')) {
                    q2.push({i,j});
                    visited2[i][j]=true;
                    while(!q2.empty()) {
                        auto cur=q2.front(); q2.pop();
                        for (int dir=0;dir<4;dir++) {
                            int nx=cur.X+dx[dir];
                            int ny=cur.Y+dy[dir];
                            if (nx<0||nx>=n||ny<0||ny>=n) continue;
                            if (visited2[nx][ny] || board[nx][ny]=='B') continue;
                            q2.push({nx,ny});
                            visited2[nx][ny]=true;
                        }
                    }
                    num2++;
                }
            if (!visited2[i][j] && board[i][j]=='B') {
                q2.push({i,j});
                visited2[i][j]=true;
                while(!q2.empty()) {
                    auto cur=q2.front(); q2.pop();
                    for (int dir=0;dir<4;dir++) {
                        int nx=cur.X+dx[dir];
                        int ny=cur.Y+dy[dir];
                        if (nx<0||nx>=n||ny<0||ny>=n) continue;
                        if (visited2[nx][ny] || board[nx][ny]!='B') continue;
                        q2.push({nx,ny});
                        visited2[nx][ny]=true;
                    }
                }
                num2++;
            }
        }
    }
    cout << num1 << " " << num2;
}
