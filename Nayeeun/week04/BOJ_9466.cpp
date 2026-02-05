#include <iostream>
#include <queue>
using namespace std;

int choice[100001];
int num[100001];

int bfs(int n) {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int student = q.front();
        q.pop();
        cnt++;

        int tar = choice[student];
        num[tar]--;
        if (num[tar] == 0) q.push(tar);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) num[i] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> choice[i];
            num[choice[i]]++;
        }
        cout << bfs(n) << "\n";
    }
    return 0;
}
