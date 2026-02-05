#include <bits/stdc++.h>
using namespace std;

char board[101][101];
bool vis[101][101];
int k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int m , int n){
    char c = board[m][n];
    queue<pair<int,int>> q;
    q.push({m,n});
    while(!q.empty()){
        auto front = q.front();q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int n_row = front.first + dy[i]; // 행 인덱스
            int n_column = front.second + dx[i]; // 열인덱스
            if(n_row < 0 || n_row >= k || n_column < 0 || n_column >= k) continue;
            if(board[n_row][n_column] != c || vis[n_row][n_column]) continue;
            vis[n_row][n_column] = true;
            q.push({n_row,n_column});
        }
    }
}

int area(){
    int res = 0;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < k ; j++){
            if(!vis[i][j]){
                  vis[i][j] = true;
                  bfs(i,j);
                  res++;
            }
        }
    }
    return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      cin >> board[i][j];
    }
  }
  
  int not_g = area(); //적록색약이 아닌사람
    
  for(int i = 0 ; i < k ; i++){
      fill(vis[i] , vis[i] + k , 0);
  }
    
  for(int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if(board[i][j] == 'G'){
          board[i][j] = 'R';
      }
    }
  }

    int g = area();

    cout << not_g << "\n" << g;
}
