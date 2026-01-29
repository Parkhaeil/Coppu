// 교훈 : queue 라는 자료구조에는 front , back , push , pop , size , empty 가 있더라

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  queue<int> Q;
  int n;
  string S;
  int input;
    
  cin >> n;
    
  for(int i = 0 ; i < n ; i++){
      cin >> S;
      if(S == "push"){
          cin >> input;
          Q.push(input);
      }else if(S == "pop"){
          if(Q.size() == 0){
              cout << -1 << "\n"; // -1 바로 cout 가능
          }else{
              cout << Q.front() << "\n" ;
              Q.pop();
          }
      }else if(S == "size"){
          cout << Q.size() << "\n";
      }else if(S == "empty"){
          if(Q.size() == 0){
              cout << 1 << "\n"; // -1 바로 cout 가능
          }else{
              cout << 0 << "\n" ;
          }
      }else if(S == "front"){
          if(Q.size() == 0){
              cout << -1 << "\n"; // -1 바로 cout 가능
          }else{
              cout << Q.front() << "\n" ;
          }
      }else{
          if(Q.size() == 0){
              cout << -1 << "\n"; // -1 같은 숫자를 바로 cout 가능
          }else{
              cout << Q.back() << "\n" ;
          }
      }
  }
   
}
