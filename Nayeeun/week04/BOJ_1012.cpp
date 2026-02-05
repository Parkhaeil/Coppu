#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y, int M, int N) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	map[y][x] = 0;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[ny][nx] == 1) {
				q.push({ nx,ny });
				map[ny][nx] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				map[y][x] = 0;
			}
		}
		while (K--) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 1) {
					cnt++;
					bfs(x, y, M, N);
				}
			}
		}
		cout << cnt << "\n";
	}
}
