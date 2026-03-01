/*
감도못잡음..

인접한 4칸을 고르는 모든 경우의 수가 
'ㅜ'를 제외한 모든 테트로미노의 회전/대칭형을 다 포함하게 됨.
=> DFS(깊이 4)

'ㅜ'모양을 DFS내부에서 바로 처리할수도 있음
=> if(depth == 2) DFS(x, y, depth + 1);
*/
#include<iostream>
#include<algorithm>
using namespace std;
int board[501][501];
bool visited[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
int mx=0;

void DFS(int x,int y,int depth,int sum) {
    if (depth==4) {
        mx=max(mx,sum);
        return;
    }
    for (int dir=0;dir<4;dir++) {
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if (nx<0||nx>=n||ny<0||ny>=m) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny]=true;
            DFS(nx,ny,depth+1,sum+board[nx][ny]);
            visited[nx][ny]=false;
        }
    }
}

// => 모든 방향을 다 더한 뒤, 하나씩 빼보는 방식
void mold(int x,int y) {
    int total=board[x][y];
    int cnt=0;
    for (int dir=0;dir<4;dir++) {
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if (nx<0||nx>=n||ny<0||ny>=m) continue;
        cnt++;
        total+=board[nx][ny];
    }
    if (cnt==4) {
        for (int dir=0;dir<4;dir++) {
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            mx=max(mx, total-board[nx][ny]);
        }
    }
    else if (cnt==3) {
        mx=max(mx,total);
    }
}

int main() {
    
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            visited[i][j] = true;
            DFS(i,j,1,board[i][j]);
            visited[i][j] = false;
            mold(i,j);
        }
    }
    cout << mx;
}