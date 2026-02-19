#include <iostream>
using namespace std;

void star(int x, int y) {
    while (x > 0 || y > 0) {
        if (x % 3 == 1 && y % 3 == 1) {
            cout << ' ';
            return;
        }
        x /= 3;
        y /= 3;
    }
    cout << "*";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            star(x, y);
        }
        cout << "\n";
    }
}
