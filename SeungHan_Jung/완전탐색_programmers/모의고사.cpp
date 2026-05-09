#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // max_element가 포함된 헤더

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3,0);
    // 1번의 반복 : 1,2,3,4,5 -> 5개
    int answer_1[5] = {1,2,3,4,5};
    // 2번의 반복 : 2,1,2,3,2,4,2,5 -> 8개
    int answer_2[8] = {2,1,2,3,2,4,2,5};
    // 3번의 반복 : 3,3,1,1,2,2,4,4,5,5 -> 10개
    int answer_3[10] = {3,3,1,1,2,2,4,4,5,5};
    // answers 의 각 요소들을 돌면서 , 
    for(int i = 0 ; i < answers.size() ; i++){
        if(answer_1[i%5] == answers[i]) answer[0]++;
        if(answer_2[i%8] == answers[i]) answer[1]++;
        if(answer_3[i%10] == answers[i]) answer[2]++;
    }
    int max_value = *max_element(answer.begin(),answer.end());
    // cout << "max_value : " << max_value << "\n";
    // for(int i = 0 ; i < answer.size() ; i++ ){
    //     cout << answer[i] << "\n";
    // }
    vector<int> final_answer = {};
    for(int i = 1 ; i <= answer.size() ; i++){
        if(answer[i-1] == max_value){
            final_answer.push_back(i);
        }
    }
    return final_answer;
}
