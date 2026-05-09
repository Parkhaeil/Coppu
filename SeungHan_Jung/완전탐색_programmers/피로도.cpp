#include <string>
#include <vector>

using namespace std;
vector<bool> visited;
int answer = -1;

// 대표적인 탐색 + 가지치기의 유형이다.
// 탐색을 하는 경우 코드의 패턴이 정해져 있다.
// 1. 종료조건(선택) -> 지금처럼 for 문으로 돌면서 재귀적으로 함수를 호출해서 탐색을 하는 경우는 따로 종료조건이 필요없는 경우들이 있다.
// 2. 새로운 시도해볼 케이스를 찾는 조건 : 주로 for , if 문의 결합
// 3. 위에서 찾은 새로 시도해볼 케이스를 누적상태에 반영하는 부분
// 4. 시도해볼 케이스를 반영한 누적상태를 넣고 탐색을 재귀적으로 호출하는 부분
// 5. 새로운 시도해볼 케이스에 대한 수행이 끝이 났으니 다시 누적상태를 원복하는 부분

void dfs(vector<vector<int>> dungeons,int hp,int count){
    answer = max(answer,count);
    
    for(int i = 0 ; i < dungeons.size() ; i++){
        if(visited[i] == false && hp >= dungeons[i][0]){ // 그래도 가지치기
            visited[i] = true;
            dfs(dungeons , hp - dungeons[i][1] , count+1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int hp = k;
    for(int i = 0 ; i < dungeons.size() ; i++){
        visited.push_back(false);
    }
    dfs(dungeons , hp , 0);
    return answer;
}
