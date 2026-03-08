/*
visited 배열이 true인 사람들은 스타트 팀, 
false인 사람들은 링크 팀으로 간주하면 간단
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s,l;
int board[21][21];
bool visited[21];
int n,sResult,lResult,mn=9999999;

// 팀 능력치 합
void sum() {
    sResult = 0;
    lResult = 0;
    s.clear();
    l.clear();
    for (int i=0;i<n;i++) {
        if (visited[i]) s.push_back(i);
        else l.push_back(i);
    }
    for (int i=0;i<n/2;i++) {
        for (int j=0;j<n/2;j++) {
            sResult+=board[s[i]][s[j]];
            lResult+=board[l[i]][l[j]];
        }
    }
    mn=min(abs(sResult-lResult),mn);
}

// 팀 선택
// => 인덱스를 넘겨주어 이전에 확인한 사람 이후부터 탐색
// => visited 배열로 팀 구분하면 됨..
void func(int depth,int idx) {
    if (depth==n/2) {
        sum();
        return;
    }
    for (int i=idx;i<n;i++) {
        if (visited[i]) continue;
        visited[i]=true;
        func(depth+1,i+1);
        visited[i]=false;
    }
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    func(0,0);
    cout << mn;
}