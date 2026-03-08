#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
int rmax = 0;

void virus(vector<vector<int>> board) {
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2)
                q.push({ i,j });
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx][ny] != 0) continue;

            board[nx][ny] = 2;
            q.push({ nx,ny });
        }
    }

    int safe = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 0)
                safe++;

    rmax = max(rmax, safe);
}

void dfs(int cnt, vector<vector<int>>& board) {
    if (cnt == 3) {
        virus(board);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                dfs(cnt + 1, board);
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << rmax;
}
