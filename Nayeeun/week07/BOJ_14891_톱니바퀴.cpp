#include <iostream>
#include <string>
using namespace std;

int gear[4][8];

void rotate(int idx, int d) {
    if (d == 1) {
        int temp = gear[idx][7];
        for (int i = 7; i > 0; i--)
            gear[idx][i] = gear[idx][i - 1];
        gear[idx][0] = temp;
    }
    else {
        int temp = gear[idx][0];
        for (int i = 0; i < 7; i++)
            gear[idx][i] = gear[idx][i + 1];
        gear[idx][7] = temp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
            gear[i][j] = s[j] - 48;
    }

    int K;
    cin >> K;

    while (K--) {
        int num, d;
        cin >> num >> d;

        int temp[4][8];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 8; j++)
                temp[i][j] = gear[i][j];

        int idx = num - 1;
        rotate(idx, d);

        int dir = d;
        for (int i = idx - 1; i >= 0; i--) {
            if (temp[i][2] != temp[i + 1][6]) {
                dir = -dir;
                rotate(i, dir);
            }
            else break;
        }

        dir = d;
        for (int i = idx + 1; i < 4; i++) {
            if (temp[i - 1][2] != temp[i][6]) {
                dir = -dir;
                rotate(i, dir);
        
            }
            else break;
        }
    }

    int res = 0;
    if (gear[0][0]) res += 1;
    if (gear[1][0]) res += 2;
    if (gear[2][0]) res += 4;
    if (gear[3][0]) res += 8;

    cout << res;
}
