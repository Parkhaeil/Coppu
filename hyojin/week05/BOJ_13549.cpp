/*
1. 현재 좌표에서 2배수 텔포로 가능한 모든 좌표에 시간 넣기
2. 걷기 앞 뒤
3. 걷기 앞 뒤에서 1번
동생 찾을 때까지 계속 반복..
*/

#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define X first
#define Y second
int n,k;
queue<int> q;
//=> walk랑 teleport로 나누지 말고 board 로 통합해서 시간 갱신
int board[100001];

void teleport(int num) {
    int temp=num;
    // 현재 위치가 0이어서 2배수 못할 때 종료
    if (!temp) return;
    // 순간이동한 위치가 최대범위 안이고 동생 위치가 아닐 때 반복
    while(temp<100001 && !board[k]) {
        // 방문 안한 곳일 때
        if (!board[temp]) {
            // 순간이동은 0초 걸리므로 이전시간 복사
            board[temp]=board[num];
            // 순간이동 한 곳에서 걷기 앞 뒤 가능하도록 큐에 넣기
            q.push(temp);
            // 동생 찾으면 멈추기
            if (temp==k) return;
        }
        temp*=2;
    }
}

int main() {
    cin >> n >> k;

    q.push(n);
    board[n]=1;
    teleport(n);
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        // 현재 위치에서 걷기로 갈 수 있는 좌표들
        vector<int> walkList={cur+1,cur-1};
        for (int nx : walkList) {
            if (nx<0||nx>=100001) continue;
            if (board[nx]) continue;
            board[nx]=board[cur]+1;
            q.push(nx);
            teleport(nx);
        }
    }
    cout << board[k]-1;
}
