#include<iostream>
#include<string>
using namespace std;

int main(int argc , const char *argv[]){
    int count[10] = {} ; // 0~9
    int a,b,c;
    
    cin >> a >> b >> c;
    int res = a * b * c;
    
    string s = to_string(res); // 쌉 가능이다! int 를 string 으로 바꿔서 char 하나씩으로 다루고 싶을때!
    
    for(char c : s){
        count[c - '0']++;
    }
    
    for(int v : count){
        cout << v << "\n";
    }
    
    return 0;
}
