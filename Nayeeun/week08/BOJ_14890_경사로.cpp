#include <iostream>
#include <vector>
using namespace std;

int N, L;
int board[101][101];

//행 또는 열을 인자로 줘서 갈 수 있는지 확인
bool check(vector<int> line) {
    bool visited[101] = { 0 };

    for (int i = 0; i < N - 1; i++) {
        int diff = line[i + 1] - line[i];
        if (diff == 0) continue;
        else if (diff == 1) {
            // 올라가는 경사로
            for (int j = 0; j < L; j++) {
                int slo = i - j;
                if (slo < 0 || line[slo] != line[i] || visited[slo])
                    return false;
                visited[slo] = true;
            }
        }
        else if (diff == -1) {
            // 내려가는 경사로
            for (int j = 1; j <= L; j++) {
                int slo = i + j;
                if (slo >= N || line[slo] != line[i + 1] || visited[slo])
                    return false;
                visited[slo] = true;
            }
        }
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++)
            row.push_back(board[i][j]);

        if (check(row)) cnt++;
    }

    for (int j = 0; j < N; j++) {
        vector<int> col;
        for (int i = 0; i < N; i++)
            col.push_back(board[i][j]);

        if (check(col)) cnt++;
    }
    cout << cnt;
}
