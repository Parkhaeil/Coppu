#include<iostream>
using namespace std;
int board[21][21];
int dice[6];
/*
  1
3 0 2
  4
  5
*/

// => swap 하기, xy 업데이트하기
// => 좌표갱신 (dx,dy) 으로 하면 더 깔끔해질수잇음..

void east() {
    int temp=dice[0];
    dice[0]=dice[3];
    dice[3]=dice[5];
    dice[5]=dice[2];
    dice[2]=temp;
}

void west() {
    int temp=dice[0];
    dice[0]=dice[2];
    dice[2]=dice[5];
    dice[5]=dice[3];
    dice[3]=temp;
}

void north() {
    int temp=dice[0];
    dice[0]=dice[4];
    dice[4]=dice[5];
    dice[5]=dice[1];
    dice[1]=temp;
}

void south() {
    int temp=dice[0];
    dice[0]=dice[1];
    dice[1]=dice[5];
    dice[5]=dice[4];
    dice[4]=temp;
}

int main() {
    int n,m,x,y,k;
    cin >> n >> m >> x >> y >> k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    int bottom=5;
    for (int i=0;i<k;i++) {
        int dir;
        cin >> dir;
        if (dir==1) {
            if (y+1==m) continue;
            y++;
            east();
        }
        if (dir==2) {
            if (y-1==-1) continue;
            y--;
            west();
        }
        if (dir==3) {
            if (x-1==-1) continue;
            x--;
            north();
        }
        if (dir==4) {
            if (x+1==n) continue;
            x++;
            south();
        }
        // 이동할 칸에 0이 써져있을때
        if (board[x][y]==0) {
            // 주사위의 바닥면 수가 칸에 복사됨
            board[x][y]=dice[5];
        }
        else {
            // 칸에 쓰여있는 수가 주사위로 복사
            dice[5]=board[x][y];
            board[x][y]=0;
        }
        cout << dice[0] << '\n';
    }
}