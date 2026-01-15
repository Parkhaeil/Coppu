#include<iostream>
using namespace std;

std::string preString , postString;

int preAlphabets[26] = {};
int postAlphabets[26] = {};

int main(){
    cin >> preString >> postString;
    
    for(int i = 0 ; i < preString.length() ; i++){
        // 당연히 String 자료형에는 인덱스 개념이 존재
        preAlphabets[preString[i] - 'a']++;
    }
    for(int i = 0 ; i < postString.length() ; i++){
        postAlphabets[postString[i] - 'a']++;
    }
    
    int ans = 0;
    for(int i = 0 ; i < 26 ; i++){
        ans += abs(preAlphabets[i] - postAlphabets[i]); // std::abs 가 iostream 헤더에 기본으로 존재한다.
    }
    
    cout << ans;
    
    return 0;
}

