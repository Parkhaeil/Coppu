#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int visited[1001][1001][2];
// x, y 위치에서 벽을 부쉈는지 아닌지를 구분해야 하므로

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int m, int n) {
    queue<pair<pair<int, int>, int>> q;
    visited[1][1][0] = 1;
    q.push({{1,1},0 });

    while (!q.empty()) {
        int tx = q.front().first.first;
        int ty = q.front().first.second;
        int broken = q.front().second;
        q.pop();

        if (tx == m && ty == n) return visited[ty][tx][broken];

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;

            if (map[ny][nx] == 0) {
                if (visited[ny][nx][broken] == 0) {
                    visited[ny][nx][broken] = visited[ty][tx][broken] + 1;
                    q.push({ {nx, ny}, broken });
                }
            }
            else {
                if (broken == 0 && visited[ny][nx][1] == 0) {
                    visited[ny][nx][1] = visited[ty][tx][broken] + 1;
                    q.push({ {nx,ny},1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            map[i][j] = c - 48;
        }
    }
    cout << bfs(m, n);
}
