#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int check = 0;
    for (auto c : s){
        if (c == '(') check++;
        else check--;
        
        if (check < 0){
            answer = false;
            break;
        }
    }
    if (check != 0) answer = false;
    return answer;
}