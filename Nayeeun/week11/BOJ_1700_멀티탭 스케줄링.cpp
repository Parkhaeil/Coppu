#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    vector<int> plug(n, 0);
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int cur = a[i];

        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (plug[j] == cur) {
                ok = true;
                break;
            }
        }
        if (ok) continue;

        for (int j = 0; j < n; j++) {
            if (plug[j] == 0) {
                plug[j] = cur;
                ok = true;
                break;
            }
        }
        if (ok) continue;

        int idx = -1;
        int late = -1;

        for (int j = 0; j < n; j++) {
            int next = 1000;

            for (int t = i + 1; t < k; t++) {
                if (a[t] == plug[j]) {
                    next = t;
                    break;
                }
            }

            if (next > late) {
                late = next;
                idx = j;
            }
        }
        plug[idx] = cur;
        cnt++;
    }
    cout << cnt;
}
