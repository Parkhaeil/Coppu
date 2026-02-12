#include <iostream>
#include <deque>
#define MAX 100001
using namespace std;

int t[MAX];

int bfs(int N, int K) {
    deque<int> dq;
    t[N] = 0;
    dq.push_front(N);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K) return t[cur];

        int next = cur * 2;
        if (next >= 0 && next < MAX && t[next] == -1) {
            t[next] = t[cur];
            dq.push_front(next);
        }

        next = cur - 1;
        if (next >= 0 && next < MAX && t[next] == -1) {
            t[next] = t[cur] + 1;
            dq.push_back(next);
        }

        next = cur + 1;
        if (next >= 0 && next < MAX && t[next] == -1) {
            t[next] = t[cur] + 1;
            dq.push_back(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < MAX; i++)
        t[i] = -1;

    cout << bfs(N, K);
}
