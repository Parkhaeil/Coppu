#include <iostream>
#include <queue>
using namespace std;

int map[201][201];
int visited[201][201][31];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int hx[8] = { -2,-2,-1,-1,1,1,2,2 };
int hy[8] = { 1,-1,2,-2,2,-2,1,-1 };

int bfs(int K, int W,int H) {
    queue<pair<pair<int, int>, int>> q;

    visited[0][0][0] = 0;
    q.push({ {0,0},0 });

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int jump = q.front().second;
        q.pop();

        if (x == W - 1 && y == H - 1) return visited[y][x][jump];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if (map[ny][nx]) continue;
            if (visited[ny][nx][jump] != -1) continue;

            visited[ny][nx][jump] = visited[y][x][jump] + 1;
            q.push({ {nx, ny}, jump });
        }

        if (jump < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];

                if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                if (map[ny][nx]) continue;
                if (visited[ny][nx][jump + 1] != -1) continue;

                visited[ny][nx][jump + 1] = visited[y][x][jump] + 1;
                q.push({ {nx, ny}, jump + 1 });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, W, H;
    cin >> K >> W >> H;

    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            cin >> map[y][x];

    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            for (int k = 0; k <= K; k++)
                visited[y][x][k] = -1;

    cout << bfs(K,W,H);
}
