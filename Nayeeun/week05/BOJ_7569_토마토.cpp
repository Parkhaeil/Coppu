#include <iostream>
#include <queue>
using namespace std;

int box[101][101][101];
int M, N, H;

int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };

int bfs() {
    queue<pair<pair<int, int>, int>> q;

    for (int z = 0; z < H; z++)
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                if (box[z][y][x] == 1)
                    q.push({ {z, y}, x });

    while (!q.empty()) {
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
            if (box[nz][ny][nx] != 0) continue;

            box[nz][ny][nx] = box[z][y][x] + 1;
            q.push({ {nz, ny}, nx });
        }
    }

    int ans = 1;

    for (int z = 0; z < H; z++)
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 0) return -1;
                if (box[z][y][x] > ans) ans = box[z][y][x];
            }

    return ans - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;

    for (int z = 0; z < H; z++)
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                cin >> box[z][y][x];

    cout << bfs();
}
