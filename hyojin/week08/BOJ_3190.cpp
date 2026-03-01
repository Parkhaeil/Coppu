/*
- dx,dy 로 상하좌우 이동하기
- 큐로 뱀 관리하기
1. 
    머리: 매 초마다 새로운 좌표가 추가
    꼬리: 매 초마다 가장 오래된 좌표가 삭제
    "가장 오래된 것을 버린다"는 특징이 큐의 선입선출 성질과 일치
2. 
    꼬리가 어디로 가야 할지 알 필요 없이
    그냥 "내가 예전에 지나온 길"만 순서대로 들고 있으면 됨
3. 
    시뮬레이션 문제의 패턴 : '길이'가 변하면서 '이동'하는 객체
    ->큐,덱
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int board[101][101];
char dir[10001];
// 상(0), 우(1), 하(2), 좌(3)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i=0;i<k;i++) {
        int x,y;
        cin >> x >> y;
        // 사과 2로 표시
        board[x-1][y-1]=2;
    }
    int L;
    cin >> L;
    for (int i=0;i<L;i++) {
        int t;
        char c;
        cin >> t >> c;
        dir[t]=c;
    }
    // => 뱀의 몸 전체 좌표를 큐에 저장
    queue<pair<int,int>> snake;
    int x=0, y=0;
    int time=0;
    int snakeDir=1;
    // 초기 상태 설정
    snake.push({x, y});
    board[x][y] = 1;

    while (true) {
        time++;
        // => nx,ny로 머리 다음 칸 계산
        int nx = x + dx[snakeDir];
        int ny = y + dy[snakeDir];

        // 범위 벗어나거나 내몸(1)과 부딫히면 게임 끝
        if (nx<0||nx>=n||ny<0||ny>=n||board[nx][ny]==1) {
            cout << time;
            return 0;
        }

        // 이동한 칸에 사과가 있다면 없애고 꼬리 그대로
        // => 큐에 머리만 추가하고 끝
        // 이동한 칸에 사과가 없다면 꼬리 위치한 칸 0으로
        // => 큐에서 가장 먼저 들어갔던 좌표(가장 오래된 좌표=꼬리)를 pop 
        //      & 그 좌표의 board 값을 다시 0으로
        if (board[nx][ny]==2) {
            board[nx][ny]=1;
            snake.push({nx,ny});
        }
        else {
            board[nx][ny]=1;
            snake.push({nx,ny});
            pair<int, int> tail = snake.front();
            board[tail.first][tail.second] = 0;
            snake.pop();

        }
        // => 현재 머리 위치 업데이트
        x = nx; 
        y = ny;
        // 방향 회전
        if (dir[time]=='L') {
            // 왼쪽 90도 회전
            snakeDir=(snakeDir+3)%4;
        }
        else if (dir[time]=='D') {
            // 오른쪽 90도 회전
            snakeDir=(snakeDir+1)%4;
        }
    }
}