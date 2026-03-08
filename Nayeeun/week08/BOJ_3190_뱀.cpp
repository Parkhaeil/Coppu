#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, L;
    cin >> N >> K;

    vector<vector<int>> board(N, vector<int>(N, 0));
    while (K--) {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }

    cin >> L;
    vector<pair<int, char>> ord(L);
    for (int i = 0; i < L; i++)
        cin >> ord[i].first >> ord[i].second;

    deque<pair<int, int>> snake;
    snake.push_back({ 0, 0 });
    board[0][0] = 2;

    int dir = 0, time = 0, idx = 0;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    while (true) {
        time++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 2)
            break;
        snake.push_front({ nx, ny });

        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
        }
        else {
            board[nx][ny] = 2;
            int tx = snake.back().first;
            int ty = snake.back().second;
            snake.pop_back();
            board[tx][ty] = 0;
        }

        if (idx < L && time == ord[idx].first) {
            if (ord[idx].second == 'D')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;

            idx++;
        }
    }
    cout << time;
}
