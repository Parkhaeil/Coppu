#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int map[9][9];
int submap[9][9]; 
// wall 을 설치할 용으로 쓸 map 도 있어야 하고 
// 반대로 한 경우의 실험이 끝났을때 그걸 원래 wall로 복구 시키기 위한 wall 도 필요 하니까
queue<pair<int,int>> q; // 바이러스의 시작점을 미리 넣어둠
vector<pair<int,int>> subq; 
// q 는 바이러스를 퍼트리면서 bfs 로 계속 오염시킬거라 
// 매 실험마다 새로 사용할 subq 라는 저장소(그렇기에 vector)가 필요함.
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool valid(int nx, int ny){ // 앞이 행 , 뒤는 열
    if(ny < 0 || ny >= N || nx < 0 || nx >= M ){
        return false;
    }else{
        return true;
    }
}

void wall(pair<int,int>p1, pair<int,int>p2, pair<int,int>p3){
    map[p1.first][p1.second] = 1;
    map[p2.first][p2.second] = 1;
    map[p3.first][p3.second] = 1;
}

void virusSpread(){
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int ny = front.first + dy[i];
            int nx = front.second + dx[i];
            
            if(valid(nx,ny) && map[ny][nx] == 0){
                map[ny][nx] = 2;
                q.push({ny,nx});
            }
        }
    }
}

int count0(){
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0){
                count++;
            }
        }
    }
    return count;
}

void recoverMap(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            map[i][j] = submap[i][j];
        }
    }
}

void recoverVirus(){
   for(int i = 0 ; i < subq.size() ; i++){
       q.push(subq[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    vector<pair<int,int>> v;
    int max = 0 , ans;
    
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            submap[i][j] = map[i][j];
            if(map[i][j] == 2){ // 이미 벽인 공간과 바이러스의 시작점인 공간을 미리 조사
                q.push({i,j});
                subq.push_back({i,j});
            }
            else if(map[i][j] == 0){
                v.push_back({i,j});
            }
        }
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = i + 1 ; j < v.size() ; j++){
            for(int k = j + 1 ; k < v.size() ; k++){
                wall(v[i],v[j],v[k]);
                virusSpread();
                int temp = count0();
                
                if(temp > max){
                    max = temp;
                }
                recoverMap();
                recoverVirus();
            }
        }
    }
    ans = max;
    cout << ans;
    
    return 0;
}
