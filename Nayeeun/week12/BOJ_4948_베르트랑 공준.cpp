#include <iostream>
using namespace std;

int pri[246913] = { 0 };
int main() {
    int n, i, j;
    pri[1] = 1;

    for (i = 2; i * i <= 246913; i++) {
        if (pri[i] == 0) {
            for (j = i * i; j <= 246913; j += i) {
                pri[j] = 1;
            }
        }
    }

    while (1) {
        cin >> n;
        if (n == 0) break;

        int cnt = 0;
        for (i = n + 1; i <= 2 * n; i++) {
            if (pri[i] == 0)
                cnt++;
        }
        cout << cnt << '\n';
    }
}
