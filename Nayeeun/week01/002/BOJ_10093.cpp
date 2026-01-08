#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);

    long long cnt = B - A - 1;
    if (cnt < 0) cnt = 0;

    cout << cnt << "\n";
    for (long long i = A + 1; i < B; i++) cout << i << " ";
}
