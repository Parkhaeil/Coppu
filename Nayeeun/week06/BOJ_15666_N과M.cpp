#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<int> result;

void NM(int cnt, int M, int start) {
    if (cnt == M) {
        for (int x : result)
            cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < num.size(); i++) {
        result[cnt] = num[i];
        NM(cnt + 1, M, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    result.resize(M);
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    NM(0, M, 0);

    return 0;
}
