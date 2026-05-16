#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
bool visited[201];
int ans=0;

void bfs(int i, vector<vector<int>>& v) {
    q.push(i);
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        visited[cur]=true;
        for (int i=0;i<v.size();i++) {
            if (i==cur) continue;
            if (!visited[i] && v[i][cur]==1) {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    ans++;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i=0;i<computers.size();i++) {
        if (!visited[i]) bfs(i,computers);
    }
    return ans;
}