/*
1. 각 판을 90도, 180도, 270도 돌린 모양을 미리 다 만들어둠
2. 백트래킹(isused 배열 사용)을 통해 5개 판의 순서를 결정
3. 재귀 함수를 통해 각 층의 회전 상태(0~3)를 선택
4. 3차원 BFS로 최단거리 탐색
*/
#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>
using namespace std;
// [판번호][회전상태][][]
int board[5][4][5][5];
int visited[5][5][5];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int mn=9999;
int bs[5];
int rs[5];
bool isused[5];

int BFS() {
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++) 
                visited[i][j][k] = -1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    visited[0][0][0]=0;
    while(!q.empty()) {
        tuple<int,int,int> cur=q.front(); q.pop();
        int curZ,curY,curX;
        tie(curZ,curY,curX)=cur;
        // => 출구 도달했는지 확인
        if (curZ==4&&curY==4&&curX==4) return visited[4][4][4];
        for (int dir=0;dir<6;dir++) {
            int nx=curX+dx[dir];
            int ny=curY+dy[dir];
            int nz=curZ+dz[dir];
            if (nx<0||nx>=5||ny<0||ny>=5||nz<0||nz>=5) continue;
            if (board[bs[nz]][rs[nz]][ny][nx]==1 && visited[nz][ny][nx]==-1) {
                visited[nz][ny][nx]=visited[curZ][curY][curX]+1;
                q.push({nz,ny,nx});
            } 
        }
    }
    return -1;
}


void rotationState(int level) {
    // => 회전 상태 다 정해졌으면 BFS실행
    if (level==5) {
        // => 입구,출구 확인
        if (board[bs[0]][rs[0]][0][0]==1 && board[bs[4]][rs[4]][4][4]==1) {
            int temp=BFS();
            if (temp!=-1) {
                mn=min(mn,temp);
            }
        }
        return;
    }
    // => 재귀로 회전상태 정하기
    for (int i=0;i<4;i++) {
        rs[level]=i;
        rotationState(level+1);
    }
}

void boardState(int level) {
    // => 판 순서 정해졌으면 회전상태 정하기
    if (level==5) {
        rotationState(0);
        return;
    }
    // => 재귀로 판 순서 정하기
    for (int i=0;i<5;i++) {
        if (!isused[i]) {
            isused[i]=true;
            // => boardstate 순서 매번 바뀌도록
            bs[level]=i;
            boardState(level+1);
            isused[i]=false;
        }
    }
}

// => 재료(회전된 판들)를 미리 다 만들어 놓고 -> 조립해서 -> BFS
void rotation() {
    // 90도 회전
    for (int p=0;p<5;p++) {
        for (int q=1;q<4;q++) {
            for (int i=0;i<5;i++) {
                for (int j=0;j<5;j++) {
                    board[p][q][i][j]=board[p][q-1][4-j][i];
                }
            }
        }
    }
}

int main() {
    for (int k=0;k<5;k++) {
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                cin >> board[k][0][i][j];
            }
        }
    }
    rotation();
    boardState(0);
    if (mn==9999) mn=-1;
    cout << mn;
}