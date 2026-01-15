#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string a, b;

    cin >> n;

    while (n--) {
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a == b) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}