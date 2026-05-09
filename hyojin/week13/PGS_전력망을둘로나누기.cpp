#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int mn=101;
// 반드시 두개의 전력망으로 분할, 전선 중 단 하나만 끊어야함
// 완전탐색으로 하나를 끊었을때 bfs로 개수탐색, 절댓값 최소인거 기록 
int bfs(int idx,int topNum, const vector<vector<int>>& v) {
    bool visited[101]={};
    queue<int> q;
    visited[topNum]=true;
    q.push(topNum);
    int num=1;;
    while(!q.empty()) {
        int d=q.front(); q.pop();
        for (int i=0;i<v.size();i++) {
            if (i==idx) 
                continue;
            if (!visited[v[i][0]] && v[i][1]==d) {
                visited[v[i][0]]=true;
                q.push(v[i][0]);
                num++;
            }
            if (!visited[v[i][1]] && v[i][0]==d) {
                visited[v[i][1]]=true;
                q.push(v[i][1]);
                num++;
            }
        }
    }
    return num;
}

void isBest(int idx, const vector<vector<int>>& v) {
    // idx=0 , wires[0] 의미.
    mn=min(mn,abs(bfs(idx,v[idx][0],v)-bfs(idx,v[idx][1],v)));
}

int solution(int n, vector<vector<int>> wires) {
    for (int i=0;i<wires.size();i++) {
        isBest(i,wires);
    }
    return mn;
}