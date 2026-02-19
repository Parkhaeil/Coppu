#include <iostream>
using namespace std;

int k;
int input[13];
int pick[6];

void re(int idx, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << pick[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (idx == k) return;

    pick[cnt] = input[idx];
    re(idx + 1, cnt + 1);
    re(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++)
            cin >> input[i];

        re(0, 0);
        cout << "\n";
    }
}
