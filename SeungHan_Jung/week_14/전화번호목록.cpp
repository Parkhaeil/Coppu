#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// c++ 의 substr 활용법 : 어떤 string 객체.substr(시작 인덱스 , 길이)

bool solution(vector<string> phone_book) {
    bool answer = true;
    std::sort(phone_book.begin(),phone_book.end()); // 오름차순 정렬(string정렬)
    for(int i = 0 ; i < phone_book.size() - 1 ; i++){
        if(phone_book[i+1].substr(0,phone_book[i].length()) == phone_book[i]){
            answer = false;
            break;
        }
    }
    return answer;
}
