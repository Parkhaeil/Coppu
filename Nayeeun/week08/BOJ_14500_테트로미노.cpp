#include <iostream>
using namespace std;

int board[501][501];
int visited[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int tmax = 0;
int b_max = 0;
int N, M;
// ㅜ 모양은 bfs로 따로 만들기 어려우므로
// 그외 모양을 bfs로 다 만들고 ㅜ를 돌리는 함수를 따로
// 시간초과 문제로 가지치기... => 남은 cnt로 가장 큰 수를 고른다 하더라도 기존의 tmax를 이기지 못하면 return
void dfs(int x, int y, int sum, int cnt) {
    if (sum + b_max * (4 - cnt) <= tmax) return;
    if (cnt == 4) {
        tmax = max(tmax, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        dfs(nx, ny, sum + board[nx][ny], ++cnt);
        visited[nx][ny] = 0;
    }
}

void except(int x, int y) {
    int mid = board[x][y];

    int sum = mid;
    int tmin = 1000;
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            cnt++;
            if (cnt == 2) return;
            continue;
        }

        sum += board[nx][ny];
        tmin = min(tmin, board[nx][ny]);
    }
    if (cnt == 1) tmax = max(tmax, sum);
    else tmax = max(tmax, sum - tmin);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            b_max = max(b_max, board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 1;
            visited[i][j] = 1;
            dfs(i, j, board[i][j], cnt);
            visited[i][j] = 0;

            except(i, j);
        }
    }
    cout << tmax;
}
