#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
int box[101][101][101];
int minDay[101][101][101];
// 기존 방향 탐색 구조 잘못됨. 아래와 같이 수정
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n,h;
    cin >> m >> n >> h;
    for (int k=0;k<h;k++) {
        // 가장 밑의 상자부터
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> box[k][i][j];
            }
        }
    }
    // 최초 일수 -1 으로 초기화
    for (int k=0;k<h;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                minDay[k][i][j]=-1;
            }
        }
    }
    queue<tuple<int,int,int>> q;
    // 시작점 넣기
    for (int k=0;k<h;k++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                // 익은 토마토 큐에 넣기
                if (box[k][i][j]==1) {
                    q.push({k,i,j});
                    minDay[k][i][j] = 0;
                }
            }
        }
    }
    // BFS
    while (!q.empty()) {
        auto cur=q.front(); q.pop();
        int z=get<0>(cur);
        int x=get<1>(cur);
        int y=get<2>(cur);
        for (int dir=0;dir<6;dir++) {
            int nz=z+dz[dir];
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if (nz<0||nz>=h||nx<0||nx>=n||ny<0||ny>=m) continue;
            // 방문한 칸이면 패스
            if (minDay[nz][nx][ny]!=-1) continue;
            // 익은 토마토 / 토마토 없는 칸이면 패스
            if (box[nz][nx][ny]!=0) continue;

            /* 현재 최소 일수 < 이미 담겨 있는 최소 일수 -> 교체 */
            // 그럴 필요없음.. 시작점 여러 개여도 BFS는 큐(선입선출)이므로 동시에 시작함

            // 최소 일수, 익은 토마토로 바꾼 후 큐에 넣기
            minDay[nz][nx][ny]=minDay[z][x][y]+1; box[nz][nx][ny]=1;
            q.push({nz,nx,ny});
         }
    }
    int ans = 0;
    for (int z=0; z<h; z++)
        for (int x=0; x<n; x++)
            for (int y=0; y<m; y++) {
                // 모두 익지 못하는 상황이면 -1 출력 후 종료
                if (box[z][x][y] == 0) {
                    cout << -1;
                    return 0;
                }
                // 최소 일수 갱신
                ans = max(ans, minDay[z][x][y]);
            }
    cout << ans;
}