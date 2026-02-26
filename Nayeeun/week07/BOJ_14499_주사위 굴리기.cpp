#include <iostream>
#include <vector>
using namespace std;

int dice[6];

int dx[5] = { 1,-1,0,0 };
int dy[5] = { 0,0,-1,1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, x, y, K;
    cin >> N >> M >> y >> x >> K;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    while (K--) {
        int cmd;
        cin >> cmd;
        cmd--;
        int nx = x + dx[cmd];
        int ny = y + dy[cmd];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;

        x = nx;
        y = ny;

        int temp = dice[0];

        if (cmd == 0) {
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
        }
        else if (cmd == 1) {
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
        }
        else if (cmd == 2) {
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        }
        else {
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
        }

        if (board[y][x] == 0) {
            board[y][x] = dice[5];
        }
        else {
            dice[5] = board[y][x];
            board[y][x] = 0;
        }
        cout << dice[0] << "\n";
    }
}
