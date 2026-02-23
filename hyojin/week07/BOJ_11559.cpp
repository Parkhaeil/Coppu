/*
1. 4개 그룹 하나 찾을 때마다 chain++
    => 1연쇄란 한 번에 터질 수 있는 모든 뿌요 그룹이 다 터진 후를 의미
2. BFS 탐색하면서 바로 location 벡터에 좌표 넣기
    => cnt >= 4일 때만 확정적으로 옮겨야
*/
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
char board[12][6];
bool visited[12][6];
vector<pair<int,int>> location;
int chain=0;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define X second
#define Y first

void chainOccur() {
    for (int j=0;j<6;j++) {
        for (int i=11;i>=0;i--) {
            if(board[i][j]!='.') {
                int idx=i;
                while (idx<11 && board[idx+1][j]=='.') {
                    board[idx+1][j]=board[idx][j];
                    board[idx][j]='.';
                    idx++;
                }
            }
        }
    }
}

bool ischain(int y, int x) {
    // BFS 확인
    // => 임시 벡터
    vector<pair<int,int>> temp;
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({y,x});
    temp.push_back({y,x});
    visited[y][x]=true;
    cnt++;
    while(!q.empty()) {
        auto cur=q.front(); q.pop();
        for (int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if (nx<0||nx>=6||ny<0||ny>=12) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx]!=board[y][x]) continue;
            q.push({ny,nx});
            visited[ny][nx]=true;
            temp.push_back({ny,nx});
            cnt++;
        }
    }
    if (cnt>=4) {
        // => 같은 턴안에서 .으로 바꾸는건 괜찮음
        for (auto i:temp) board[i.Y][i.X]='.';
        return true;
    }
    else return false;
}

int main() {
    for (int i=0;i<12;i++) {
        for (int j=0;j<6;j++) {
            cin >> board[i][j];
        }
    }
    while (true) {
        location.clear();
        // 종료조건:현재 board에서 연쇄 가능한지? 없으면 break
        // => 초기화..
        for (int i=0;i<12;i++) {
            for (int j=0;j<6;j++) {
                visited[i][j]=false;
            }
        }
        bool flag=false;
        for (int i=0;i<12;i++) {
            for (int j=0;j<6;j++) {
                if (board[i][j]!='.' && !visited[i][j]) {
                    if (ischain(i,j)) {
                        flag=true;
                    }
                }
            }
        }
        if (!flag) break;
        // => 1연쇄란 한 번에 터질 수 있는 모든 뿌요 그룹이 다 터진 후를 의미함..
        // => . 으로 다 바꾸고 맨 마지막에 중력 적용
        chainOccur();
        chain++;
    }
    cout << chain;
}