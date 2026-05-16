#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,vector<string>> u;
    for(int i = 0 ; i < clothes.size() ; i++){
        u[clothes[i][1]].push_back(clothes[i][0]);
    } // 굳이 일렇게 쓸 필요가 없지만 , 확장성을 위해 써보았다. 키로 사용되는 값에 해쉬를 취한 값을 메모리 주소로 하는 곳에 특정한 벡터가 저장된 주소가 들어간다고 보면 된다.
    
    // unordered_map 을 순회하는 방법은 by iterator
    vector<int> clothes_per_position;
    for(auto i = u.begin() ; i != u.end() ; i++){
        clothes_per_position.push_back(i->second.size());
        // 왜 이렇게 써야 하냐면 , i 는 인덱스가 아님 이건 iterator 즉 완변히 포인터는 아니긴 하지만 포인터와 비슷한 속성을 가진 iterator 타입의 객체이다.
        // 이 객체가 가진 속성들에는 뭐가 있냐 : key 와 value 라는 두개의 속성이 존재함
    }
    for(int i = 0 ; i < clothes_per_position.size() ; i++){
        answer *= (clothes_per_position[i] + 1);
    }
    answer--;
    return answer;
}
