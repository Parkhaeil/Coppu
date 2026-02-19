#include <iostream>
#include <vector>
using namespace std;

vector<string> build(int n) {
    if (n == 1) {
        return { "*" };
    }

    vector<string> prev = build(n / 3);
    vector<string> result;

    // 위 3블록
    for (const string& row : prev) {
        result.push_back(row + row + row);
    }

    // 가운데 3블록 
    string blank(n / 3, ' ');
    for (const string& row : prev) {
        result.push_back(row + blank + row);
    }

    // 아래 3블록
    for (const string& row : prev) {
        result.push_back(row + row + row);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> answer = build(N);

    for (const string& row : answer) {
        cout << row << '\n';
    }

    return 0;
}
