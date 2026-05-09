#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
string arr[5]={"A","E","I","O","U"};
// 알파벳으로 만들수있는 모든 경우의 수 . 중복상관없음
void func(string s) {
    v.push_back(s);
    if (s.size()==5) {
        return;
    }
    for (int i=0;i<5;i++) {
        func(s+arr[i]);
    }
}
// 사전 미리 만들고 비교
int solution(string word) {
    for (int i=0;i<5;i++) {
        func(arr[i]);
    }
    for (int i=0;i<v.size();i++) {
        if (v[i]==word)
            return i+1;
    }
}