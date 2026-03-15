#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long r_num(long long x) {
    long long r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> v(N);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        v[i] = r_num(x);
    }
    sort(v.begin(), v.end());

    for (long long x : v)
        cout << x << "\n";
}
