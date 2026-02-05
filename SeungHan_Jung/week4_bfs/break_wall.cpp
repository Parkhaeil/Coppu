#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1000];          // 0/1 문자열로 받기
int dist[1000][1000][2];     // [x][y][0/1]  벽 안부숨 / 한 번 부숨 : 각각의 경우에 경로
// 항상 첫 방문이 무조건 가장 적은 비용일 거임.

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {
    // dist 초기화
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 1;          // 시작: (0,0)까지 거리 1, 아직 벽 안 부숨
    q.push({0, 0, 0});          // x, y, broken

    while(!q.empty()) {
        auto [x, y, broken] = q.front();
        q.pop();

        if(x == n - 1 && y == m - 1)
            return dist[x][y][broken];

        int nd = dist[x][y][broken] + 1;

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;

            // 1) 빈 칸으로 이동 (벽 안 부숨)
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nd;
                q.push({nx, ny, broken});
            }

            // 2) 벽인데, 아직 한 번도 안 부쉈다면 부수고 가기
            if(board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nd;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

// 사실상 큐에 추가할 수 있는 저 2가지의 경우의 수를 떠올릴 수 있느지가 메인이 아니었을까

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];

    cout << bfs();
}
