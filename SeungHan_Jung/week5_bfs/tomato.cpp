#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[103][103][103];
int dist[103][103][103];

int main(void){
    queue<tuple<int,int,int>> q;
    int c,r,z;
    cin >> c >> r >> z;
    for(int i = 0 ; i < z ; i++){
        for(int j = 0 ; j < r ; j++){
            for(int k = 0 ; k < c ; k++){
                int temp;
                cin >> temp;
                board[j][k][i] = temp;
                // for문을 board 상에서 돌릴 필요가 없다 
                // -> 완전히 안 볼 자리 / 1인 자리 / 0인 자리 이 3가지의 경우 밖에 없고 
                // 이 3가지 중에서도 안볼자리와 0인자리를 제외한 1인 자리만 보면 되기 때문
                // 1인 자리에 의해 주변에 1이 되는 자리들이 있다면 큐에 넣어주면 그만 
                // 이 차이점이 다른 문제들과의 차이점
                if(temp == 1) q.push({j,k,i});
                if(temp == 0) dist[j][k][i] = -1; 
                // 구별점 -> 안 볼 자리와 1인 자리는 그냥 똑같이 탐색을 안 할자리
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // tuple 은 이렇게 한번에 값을 싹 할당 받는다.
        int curX,curY,curZ;
        tie(curX,curY,curZ) = cur;
        for(int i = 0 ; i < 6 ; i++){
                    int nx = curX + dx[i];
                    int ny = curY + dy[i];
                    int nz = curZ + dz[i];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= z){
                        continue;
                    }
                    // 아 이런 조건이면 되겠다 -> 이거의 반대만 continue로 넘겨버리고 나머지 경우들을
                    // 싸그리 한번에 처리해야겠다
                    if(dist[nx][ny][nz] >= 0) continue;
                    dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                    // 처음부터 1이었거나 0인 아이는 모두 0
                    // 처음부터 1이었거나 0인 아이에 의해 1이 된 아이들은 1
                    // 처음부터 1이었거나 0인 아이에 의해 1이 된 아이들에 의해 1이 된 아이들은 2
                    // etc..
                    q.push({nx,ny,nz});
                }
    }
  int ans = 0;
    // 죽일 놈의 축
  for (int i = 0; i < z; i++) {
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        if (dist[j][k][i] == -1) {
          cout << -1 << "\n";
          return 0;
        }
        ans = max(ans, dist[j][k][i]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
