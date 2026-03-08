#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int arr[101][101]; // 1 뱀 2 사과 : N 은 반드시 
int N, K, L; // 맵 크기 , 사과의 수 , 뱀의 방향 전환의 수
queue<pair<int , char>> q;
int ans = 0;
int dir_idx = 1; // 방향 상우하좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0 ; i < K ; i++){
        int apple_x,apple_y;
        cin >> apple_y >> apple_x;
        arr[apple_y][apple_x] = 2;
    }
    
    cin >> L;
    for(int i = 0 ; i < L ; i++){
        int time ; char direction;
        cin >> time >> direction;
        q.push({time, direction});
    }
    
    arr[1][1] = 1 ; // 시작점은 1,1 이라고 문제에서 그랬으니까
    // 뱀 같은 경우는 길이가 일정하면 계속 앞으로 이동하면서 새롭게 push 하고
    // 뒤에서는 pop 하고 이렇게 양쪽으로 움직여야 하기 때문에 , deque 으로 설정하고 ,
    // 그 deque 의 각 요소는 pair<int,int> 즉 좌표겠지요
    // 어차피 동선에 따라서 좌표를 추가하고 또 삭제하는 거기 때문에 뭐 그 중간의 인자들을 걱정할 필요는 없음
    deque<pair<int,int>> snake;
    snake.push_back({1,1});
    
    while(1){
        ans++;
        // "뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다."
        auto current = snake.back();
        int nRow = current.first + dy[dir_idx];
        int nCol = current.second + dx[dir_idx];
        if(nRow <= 0 || nRow > N || nCol <= 0 || nCol > N || 
          arr[nRow][nCol] == 1){
            break;
        }
        
        if(arr[nRow][nCol] !=2){
            // 사과 아님 -> 뱀의 길이를 유지해야 하기에 if 문 밖에서 back 에 값을 추가하고 
            // front 에 값 즉 꼬리의 값을 버려야 함.
            arr[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        // 사과가 맞던 아니던 어쨋든 머리 부분은 앞으로 나아 가야 하니까
        arr[nRow][nCol] = 1;
        snake.push_back({nRow,nCol});
        
        if(ans == q.front().first){
            char direct = q.front().second;
            if(direct == 'D'){
                dir_idx = (dir_idx + 1)%4;
            }else{
                dir_idx = (dir_idx + 3)%4;
            }
            q.pop();
        }
        
    }
    
    cout << ans << '\n';
    
}
