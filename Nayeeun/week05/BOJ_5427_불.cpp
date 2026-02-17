#include <iostream>
#include <queue>
using namespace std;

char input[1001][1001];
// 불 bfs, 상근의 이동 bfs
int fire[1001][1001];
int mv[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int w, int h) {
    queue<pair<int, int>> fq, mq;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            fire[y][x] = -1;
            mv[y][x] = -1;
 
            if (input[y][x] == '*') {
                fq.push({ x, y });
                fire[y][x] = 0;
            }
            else if (input[y][x] == '@') {
                mq.push({ x, y });
                mv[y][x] = 0;
            }
        }
    }

    //불의 bfs랑 사람의 bfs랑 구분해서
    while (!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (input[ny][nx] == '#') continue;
            if (fire[ny][nx] != -1) continue;

            fire[ny][nx] = fire[y][x] + 1;
            fq.push({ nx, ny });
        }
    }

    while (!mq.empty()) {
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();

        int t = mv[y][x];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) return nt;
            if (input[ny][nx] == '#') continue;
            if (mv[ny][nx] != -1) continue;
            // 상근이가 가는 지점에 불이 먼저 도착해있으면 안됨
            if (fire[ny][nx] != -1 && fire[ny][nx] <= nt) continue;

            mv[ny][nx] = nt;
            mq.push({ nx, ny });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int w, h;
        cin >> w >> h;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cin >> input[y][x];
            }
        }

        int ans = bfs(w, h);
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}
