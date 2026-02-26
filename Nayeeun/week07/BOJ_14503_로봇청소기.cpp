#include <iostream>
using namespace std;

int board[50][50];
int visited[50][50];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int x, y, d;
    cin >> y >> x >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int cnt = 0;

    while (true) {
        if (!visited[y][x]) {
            visited[y][x] = 1;
            cnt++;
        }

        bool moved = false;

        for (int i = 0; i < 4; i++) {

            d = (d + 3) % 4;

            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (board[ny][nx] == 0 && !visited[ny][nx]) {
                    x = nx;
                    y = ny;
                    moved = true;
                    break;
                }
            }
        }

        if (moved) continue;

        int back = (d + 2) % 4;
        int bx = x + dx[back];
        int by = y + dy[back];

        if (bx < 0 || bx >= M || by < 0 || by >= N || board[by][bx] == 1)
            break;

        x = bx;
        y = by;
    }
    cout << cnt;
}
