#include<bits/stdc++.h>
using namespace std;

bool compare(string &a , string &b){
    int len_a = a.length(); 
    //  a 는 string 타입의 객체라는 것을 잊으면 안 된다.
    // -> 생각해보면 length 를 세는 어떠한 함수로 그 길이를 세지 길이가 하나의 속성으로 떡하니 있다는 것도 말이 안 됨
    int len_b = b.length();
    if(len_a == len_b){
        return a < b; // string끼리의 대소비교는 원래 사전 순으로 자동으로 되니까 +compare 은 절대 <= 같은 형태 안 됨! 메모리가 꼬인데요 그래서 segfault 가 뜸
    }else{
        return len_a < len_b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    string s;
    vector<string> arrays;
    
    for(int i = 0 ; i < N ; i++){
        cin >> s;
        arrays.push_back(s);
    }
    
    sort(arrays.begin() , arrays.end() , compare);
    arrays.erase(unique(arrays.begin() , arrays.end()) , arrays.end());
        // erase 는 vector 클래스 소속의 메서드로써 잊기 때문에! , 좋은거 하나 배워갑니다.
    
    for(int i = 0 ; i < arrays.size() ; i++){
        cout << arrays[i] << "\n";
    }
}
