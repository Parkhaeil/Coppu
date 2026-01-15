// 앞에서는 LIST 이용 또 힙 구조 를 이용했었다 특히 큐를 이용했을때는
// 순차적으로 돌면서 큐에 값들을 다 넣은 다음에 즉 PUSH() 한 다음 
// 우리가 찾는 순번의 값이 아니라면 PUSH(Q.front()) 하고 POP()
// 우리가 찾는 값이었으면 COUT << Q.front() 하고 , POP() 했었다.

// 이번에는 비슷한 듯 다른 자료 구조인 vector 을 사용해 볼 예정
// 큐는 인덱스의 개념이 없고 주소의 개념만 있었다
// 가장 크고 중요한 차이점으로 vector는 인덱스를 쓸 수 있었다.
// vector 는 동적 크기 설정이 가능하다는 특징이 있지만 , queue 도 뭐
// 인자 삽입에 제한은 없기에 그리 큰 차이가 있나 싶긴 함.
// 인덱스 쓰니까 깔끔하기는 한데 이거 벡터 앞에걸 안 지우고 (인덱스 쓰려고 하니까 못 지우잖아)
// 계속 뒤로 추가 하니까 메모리 진짜 폭발 해버림.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int n,k;
  cin >> n >> k;
  vector<int> V,ans;
    
  for(int i = 0 ; i < n ; i++){
      V.push_back(i+1);
  }
    
  for(int i = 0 ; ans.size() < n ; i++){
      if(i%k == k-1){
          ans.push_back(V[i]);
      }else{
          V.push_back(V[i]);
      }
  }
    
  cout << '<';
  for(int i = 0 ; i < ans.size() ; i++){
      if(i == n - 1){
          cout << ans[i];
      }else{
          cout << ans[i] << ", ";
      }
  }
  cout << '>'; 
}
