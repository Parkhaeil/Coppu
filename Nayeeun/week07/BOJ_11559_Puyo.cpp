#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

char board[12][6];
int visited[12][6];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void gravity() {
    for (int x = 0; x < 6; x++) {
        int bottom = 11;
        for (int y = 11; y >= 0; y--) {
            if (board[y][x] != '.') {
                board[bottom][x] = board[y][x];
                if (bottom != y) board[y][x] = '.';
                bottom--;
            }
        }
        for (int y = bottom; y >= 0; y--)
            board[y][x] = '.';
    }
}

bool bfs(int x, int y) {
    queue<pair<int, int> > q;
    vector<pair<int, int> > block;

    char c = board[y][x];
    visited[y][x] = 1;
    q.push({ x,y });
    block.push_back({ x,y });

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = tx + dx[d];
            int ny = ty + dy[d];

            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx] != c) continue;

            visited[ny][nx] = 1;
            q.push({ nx,ny });
            block.push_back({ nx,ny });
        }
    }

    int size = block.size();

    if (size < 4) return false;

    for (int i = 0; i < size; i++) {
        int bx = block[i].first;
        int by = block[i].second;
        board[by][bx] = '.';
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            board[i][j] = s[j];
        }
    }
    int cnt = 0;

    while (true) {
        for (int y = 0; y < 12; y++)
            for (int x = 0; x < 6; x++)
                visited[y][x] = 0;

        bool match = false;

        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {
                if (board[y][x] == '.' || visited[y][x]) continue;
                if (bfs(x, y)) match = true;
            }
        }

        if (!match) break;

        gravity();
        cnt++;
    }

    cout << cnt;
}
