#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int land[101][101];
int bridge[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int N) {
    int id = 0;
    queue<pair<int, int>> q, bq;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == 0) continue;
            if (land[y][x] != 0) continue;

            id++;
            land[y][x] = id;
            q.push({ x, y });

            while (!q.empty()) {
                int top_x = q.front().first;
                int top_y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = top_x + dx[i];
                    int ny = top_y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                    if (map[ny][nx] == 0) continue;
                    if (land[ny][nx] != 0) continue;

                    land[ny][nx] = id;
                    q.push({ nx, ny });
                }
            }
        }
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (map[y][x] == 1) {
                bridge[y][x] = 0;
                bq.push({ x, y });
            }

    int min = 10000;

    while (!bq.empty()) {
        int top_x = bq.front().first;
        int top_y = bq.front().second;
        bq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = top_x + dx[i];
            int ny = top_y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            // 영역 확장
            if (bridge[ny][nx] == -1) {
                bridge[ny][nx] = bridge[top_y][top_x] + 1;
                land[ny][nx] = land[top_y][top_x];
                bq.push({ nx, ny });
            }
            else if (land[ny][nx] != land[top_y][top_x]) {
                int cand = bridge[ny][nx] + bridge[top_y][top_x];
                if (cand < min) min = cand;
            }
        }
    }

    return min;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            land[y][x] = 0;
            bridge[y][x] = -1;
        }
    }

    cout << bfs(N);
}
