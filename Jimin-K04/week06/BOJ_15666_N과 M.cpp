#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;
vector<int> seq;

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << seq[i] << (i + 1 == M ? '\n' : ' ');
        }
        return;
    }

    int prev = -1; 
    for (int i = start; i < N; i++) {
        if (a[i] == prev) continue;  
        prev = a[i];

        seq.push_back(a[i]);
        dfs(depth + 1, i);            // i부터 다시 선택 가능
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());
    dfs(0, 0);

    return 0;
}
