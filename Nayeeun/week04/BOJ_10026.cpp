#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
char input[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y, int N, bool blind) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	char color = map[y][x];
	map[y][x] = 0;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[ny][nx] == 0) continue;

			if (!blind) {
				if (map[ny][nx] != color) continue;
			}
			else {
				if (color == 'B') {
					if (map[ny][nx] != 'B') continue;
				}
				else {
					if (map[ny][nx] == 'B') continue;
				}
			}

			q.push({ nx,ny });
			map[ny][nx] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> input[y][x];

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			map[y][x] = input[y][x];

	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] != 0) {
				cnt++;
				bfs(x, y, N, false);
			}
		}
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			map[y][x] = input[y][x];

	int cnt2 = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] != 0) {
				cnt2++;
				bfs(x, y, N, true);
			}
		}
	}

	cout << cnt << " " << cnt2;
	return 0;
}
