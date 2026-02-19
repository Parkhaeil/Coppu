#include <iostream>
using namespace std;

char input[3100][6200];

void star(int x, int y, int size) {
    if (size == 3) {
        input[y][x] = '*';
        input[y + 1][x - 1] = '*';
        input[y + 1][x + 1] = '*';
        for (int i = -2; i <= 2; i++)
            input[y + 2][x + i] = '*';
        return;
    }

    int s = size / 2;

    star(x, y, s);
    star(x - s, y + s, s);
    star(x + s, y + s, s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 2 * N; x++) {
            input[y][x] = ' ';
        }
    }
    star(N - 1, 0, N); //삼각형의 맨 위 꼭짓점의 좌표
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 2 * N; x++)
            cout << input[y][x];
        cout << "\n";
    }
}
