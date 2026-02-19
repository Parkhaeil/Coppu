#include <iostream>
using namespace std;

char input[65][65];

void quadTree(int x, int y, int size) {
    char first = input[y][x];
    bool same = true;

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (input[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        cout << first;
        return;
    }

    int s = size / 2;

    cout << "(";
    quadTree(x, y, s);
    quadTree(x + s, y, s);
    quadTree(x, y + s, s);
    quadTree(x + s, y + s, s);
    cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    quadTree(0, 0, N);
}
