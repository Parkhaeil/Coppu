#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[1000000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n);

    long long sum = 0;
    int l = a[0].first, r = a[0].second;

    for (int i = 1; i < n; i++) {
        if (a[i].first <= r) {
            if (a[i].second > r)
                r = a[i].second;
        }
        else {
            sum += (long long)(r - l);
            l = a[i].first;
            r = a[i].second;
        }
    }
    sum += (long long)(r - l);
    cout << sum;
}
