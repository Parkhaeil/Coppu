#include<iostream>
using namespace std;
char board[1024*3][1024*3*2];

void func(int n,int x, int y) {
    // => 가장 작은 삼각형은 n=1짜리 점 하나가 아니라 높이가 3인 삼각형
    if (n==3) {
        board[x][y]='*';
        board[x+1][y-1]='*'; board[x+1][y+1]='*';
        for (int i=y-2;i<=y+2;i++) 
            board[x+2][i]='*';
        return;
    }
    func(n/2,x,y);
    func(n/2,x+n/2,y-n/2);
    func(n/2,x+n/2,y+n/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0;i<n;i++) 
        // => 밑칸 2*n-1
        for (int j=0;j<n*2-1;j++)
            board[i][j]=' ';
    func(n,0,n-1);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n*2-1;j++)
            cout << board[i][j];
        cout << '\n';
    }
}