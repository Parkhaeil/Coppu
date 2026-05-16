#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// 대박사건 : std::stoi 는 있는데 , std::itos 는 없음
// 대신 std::to_string 은 있다는 말씀
// 그리고 이 () 안에는 int 뿐만 아니라 여러 자료형이 들어갈 수도 있음

// 1번째 시도

// 처음에는 탐색을 통해서 들어온 수들을 통해서 만들어낼 수 있는 모든 종류의 수를 만들고 sort 를 해야 하나 싶었는데 말도 안 되는 생각이었음
// 그냥 복잡도가(n-factorial 급이 나옴) : 가능한 모든 경우의 수를 다 만드는 것이고 탐색을 하면서 조건이 안 맞아서 더 이상 진행을 안 할래 이런 경우가 나와야 탐색을 하는 것이 복잡도 상 의미가 있는데 이건 무조건 모든 경우를 다 봐야 하는거니까

// 2번째 시도
// 2번째는 새로 들어오는 값을 벡터의 맨 뒤에 끼워넣고 기존 값이랑 합쳤을때 더 큰지 작은지를 비교하면서 swap 을 하면서 위로 깨고 올라가는 그런 상황을 만들려고 했음 
// -> 이런 방식을 insertion sort 라 하고 , 미안하지만 insertion sort 는 최악의 경우
// 즉 정말 매번 swap 을 해야 하는 경우 O(n^2)이 된다. -> 지금처럼 입력값이 100,000 개인 상황에서는 무조건 터짐
// string solution(vector<int> numbers) {
//     string answer = "";
//     vector<string> v; 
//     // swap 의 기능이 필요하기 때문에 그냥 vector 로 만들고 반복적으로 swap 한다
//     for(int i = 0 ; i < numbers.size() ; i++){
//         if(i == 0){
//             v.push_back(to_string(numbers[i]));
//             continue;
//         }
//         v.push_back(to_string(numbers[i]));
//         int cur = v.size() -1;
//         for(int j = v.size() - 2 ; j >= 0  ; j--){
//             // 지금 벡터가 앞 인덱스(0과 가까운 인덱스) 에 있는 수가 최종 출력수의 더 큰 자리수에 오도록 설정 , v[cur] 가 새로이 들어온 문자열이고, v[j] 가 기존에 들어가 있는 string이다. -> 맨 뒤에서 부터 위로 뿌시면서 올라가는 느낌
//             if((v[j] + v[cur]) > (v[cur] + v[j])){ 
//                 // 기존의 수가 여전히 앞에 있는 경우가 더 큰 수를 만들어내는 경우
//                 break;
//             }
//             swap(v[cur] , v[j]);
//             cur--;
//         }
//     }
    
//     for(int i = 0 ; i < v.size() ; i++){
//         answer += v[i];
//     }
    
//     return answer;
// }

// 3번쨰 시도 : 정렬에서는 무조건 커스터마이징 된 비교 함수와 sort 함수를 불러서 사용하는 것이 정답인 이유
// 우선 원소의 수가 많은 경우 sort 는 그 내부에서 quicksort 를 사용함
// 생각해보면 , 우리가 끼워 넣을 배열을 만든 다음에 피벗을 기준으로 , 그리고 우리가 커스터마이징한 함수를 기준으로 양쪽에서 밀고 들어오기 떄문에 알고리즘 시간에 배웠듯 O(nlog_2(n))
// sort 라는 함수를 호출을 할떄 , 그 내부의 cmp 함수와 그 cmp 함수의 입력으로 들어가는 해당 턴의 비교대상값과 피벗이 그 함수의 결과에 따라 어떻게 정렬이 일어나게 되는지를 notion 에 자세하게 정리해 놓았다.
// 완전 간간단단
bool cmp(string a , string b){
    return a + b > b + a; 
    // 정렬이 다 끝났을때 , 임의의 두 수 a 가 b 를 딱 뽑았을떄
    // a가 b보다 앞에 있기 위한 조건이 뭐야
    // 이 문제에서는 : "ab" 가 "ba" 보다 커야 하는 거잖아
}

string solution(vector<int> ints) {
    string answer = "";
    vector<string> numbers;
    for(int i : ints){
        numbers.push_back(to_string(i));
    }
    std::sort(numbers.begin() , numbers.end() , cmp);
    if(numbers[0] == "0"){
        return "0";
    }
    for(int i  = 0 ; i < numbers.size() ; i++){
        answer += numbers[i];
    }
    return answer;
}
