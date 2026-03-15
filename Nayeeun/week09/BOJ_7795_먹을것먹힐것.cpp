#include <iostream>
#include <algorithm>
using namespace std;

int A[20001];
int B[20001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < M; i++) cin >> B[i];

        sort(B, B + M);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = M;

            while (left < right) {
                int mid = (left + right) / 2;

                if (B[mid] < A[i]) left = mid + 1;
                else right = mid;
            }
            ans += left;
        }
        cout << ans << "\n";
    }
}
