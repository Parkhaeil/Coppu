#include <iostream>
#include <vector>
using namespace std;

int N;
int S[21][21];
bool visited[21];
int ans = 10000;

void dfs(int pla, int cnt) {
    if (cnt == N / 2) {
        int start = 0;
        int link = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (visited[i] && visited[j])
                    start += S[i][j] + S[j][i];
                else if (!visited[i] && !visited[j])
                    link += S[i][j] + S[j][i];
            }
        }
        ans = min(ans, abs(start - link));
        return;
    }

    for (int i = pla; i < N; i++) {
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    dfs(0, 0);
    cout << ans;
}
