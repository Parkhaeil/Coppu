#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> S;

    for(char c : s){
        if(c == ')'){
            if(S.size() == 0){
                return false;
            }else{
                S.pop();
            }
        }else{
            S.push(1);
        }
    }

    if(S.empty()){
        return true;
    }else{
        return false;
    }
}
