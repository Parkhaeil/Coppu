#include <iostream>
#include <queue>
using namespace std;

int knight[301][301];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

int bfs(int l, int x, int y, int tx, int ty) {
    queue<pair<int, int>> q;

    knight[y][x] = 0;
    q.push({ x, y });

    while (!q.empty()) {
        int top_x = q.front().first;
        int top_y = q.front().second;
        q.pop();

        if (top_x == tx && top_y == ty) return knight[top_y][top_x];

        for (int i = 0; i < 8; i++) {
            int nx = top_x + dx[i];
            int ny = top_y + dy[i];

            if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if (knight[ny][nx] != -1) continue;

            knight[ny][nx] = knight[top_y][top_x] + 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int l;
        cin >> l;

        for (int i = 0; i < l; i++)
            for (int j = 0; j < l; j++)
                knight[i][j] = -1;

        int x, y, tx, ty;
        cin >> x >> y;
        cin >> tx >> ty;

        cout << bfs(l, x, y, tx, ty) << "\n";
    }
}
