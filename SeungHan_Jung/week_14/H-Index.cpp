#include <string>
#include <vector>
#include<algorithm>

// 예외경우가 있는 것 같은데 , 
// [0] 이거 -> 논문이 1개인데 , 그 1개 마저도 인용의 횟수가 0회임 -> 출력이 0이어야 함 
// 그 경우를 제외하고는 유일하게 예외가 발생할 수 있는 것 같은 경우인 인자 수가 1개인 경우에서도 [1] 이상 부터 다 처리가 가능해서 문제가 발생 x
// 또는 [1,3,3,4,5] 이런거는? 오 되네 결국은 값이 같은 것의 마지막 3에 걸리게 되니까

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int start_index , end_index;
    std::sort(citations.begin(),citations.end()); // 오름차순 정렬
    if(citations.size() == 1 && citations[0] ==0){
        return 0;
    }
    for(int i  = 0 ; i < citations.size() ; i++){
        if(citations[i] >= citations.size() - i){
            return (citations.size() - i);
        }
    }
}
