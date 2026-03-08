#include <iostream>
#include <vector>
using namespace std;

int num[11];
int op[4];

int rmax = -1000000000;
int rmin = 1000000000;
int N;

void dfs(int cnt, int res) {
    if (cnt == N) {
        rmax = max(rmax, res);
        rmin = min(rmin, res);
        return;
    }

    if (op[0] > 0) {
        op[0]--;
        dfs(cnt + 1, res + num[cnt]);
        op[0]++;
    }

    if (op[1] > 0) {
        op[1]--;
        dfs(cnt + 1, res - num[cnt]);
        op[1]++;
    }

    if (op[2] > 0) {
        op[2]--;
        dfs(cnt + 1, res * num[cnt]);
        op[2]++;
    }

    if (op[3] > 0) {
        op[3]--;
        dfs(cnt + 1, res / num[cnt]);
        op[3]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    dfs(1, num[0]);

    cout << rmax << "\n" << rmin;
}
