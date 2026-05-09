#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> made;

void dfs(string numbers, vector<bool>& visited, string cur){
        if(cur != ""){
            made.insert(stoi(cur));
        }
        for(int i = 0 ; i < visited.size();i++){
            if(!visited[i]){
                // 사용을 안 했으면 이걸 사용을 해야지
                visited[i] = true; // 항상 dfs 등을 통해서 탐색을 하면 이게 참 중요하지 상태를 표시하고 끝나면 원복하는 것
                dfs(numbers,visited,cur+numbers[i]);
                visited[i] = false;
            }
        }
    }

int solution(string numbers) {
    int answer = 0;
    int n = 10000000;
    vector<int> is_prime(n,true);
    is_prime[0] = false;
    is_prime[1] = false;
    // 나올 수 있는 7자리의 수들 중 소수인 수와 소수가 아닌 수를 미리 다 정해놓는다.
    for(int i = 2 ; i <= n ; i++){
        if(is_prime[i]){
            for(int j = i*i ; j <= n ; j+=i){
                is_prime[j] = false;
            }
        }
    }
    // 나올 수 있는 수들의 범위가 정해져 있다.
    // 그 공간을 탐색을 하면서 우리가 찾는 하나하나의 수들에 대해 소수인지 판별을 한다
    // 유한 공간을 탐색하는 방법에는 dfs , bfs 등이 있고 주로 재귀함수 호출을 사용한다
    // 우리가 알고리즘 시간에 배운 백트래킹은 곧 dfs + pruning 이라고 보면 된다.
    // 유한공간을 탐색한다고 할떄 거의 대부분이 백트래킹이므로 탐색을 해야 한다고 느낀 순간 백트래킹을 하기 위해 공간을 생각하고 자를 조건을 생각한다.
    // 유한 공간을 먼저 생각해야 하는데 지금 문장의 경우는
    // 루트에 {0,1,1} 이 있고 그 밑에 자식노드 3개 (각각 0,1,1) 뭐 이런 식으로 그려지는 트리가 곧 유한 공간인 듯한 느낌이다. 이미 어떤 수가 검사 되었는지 여부를 통해서 특정 노드는 검사를 안 해야겠다 이런 결론으로 이어지는데 ,노드를 검사하는 방식이기에 사실 백트래킹의 무기인 pruning 이 딱히 큰 효과를 발휘하지 못하는 듯 그리고 그냥 각 노드가 end에 도착할 떄마다 set 에 넣으면서 각 엔드노드가 중복인지 아닌지를 판단한다고 생각하면 될 것 같다.
    
    made.clear();
    vector<bool> visited(numbers.size(),false);
    dfs(numbers,visited,""); // 이 함수가 완료가 되면 set 이 나올 수 있는 모든 숫자들로 꽉 차 있을 것
    
    for(int i : made){
        if (is_prime[i] == true){
            //cout << i;
            answer++;
        }
    }
    
    return answer;
}
