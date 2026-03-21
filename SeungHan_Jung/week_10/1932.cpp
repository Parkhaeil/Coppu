#include <bits/stdc++.h>
using namespace std;

int a[505][505] = {0,};
int d[505][505] = {0,};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int N;
  cin >> N;
  
  for(int i = 1 ; i <= N ; i++){
      for(int j = 1 ; j <= i ; j++){
          cin >> a[i][j]; 
      }
  }
    
  d[1][1] = a[1][1];
  for(int i = 2 ; i <= N ; i++){
      for(int j = 1 ; j <= i ; j++){
          d[i][j] = max(d[i-1][j-1],d[i-1][j]) + a[i][j];
      }
   }

   cout << *max_element(d[N] + 1 , d[N] + 1 + N);
   // 아주 유용한 함수를 알게 되어 버렸다
   // max(int , int) 또는 max(string , string) 등은 잘 알고 있었지만
    // 어떤한 배열이나 벡터 등과 같은 메모리 상에 쭉 나열되어 있는 값들의 최대 및 최소를 구하고 싶을때
    // 사용할 수 있는 유의미한 유틸리티가 max_element() 이고 이 메서드의 반환값은 int , string 등의 실제 값이 아닌 주소 값이기 떄문에 실제 그 주소 속의 값을 이용을 할려면 위처럼 참조 포인터를 붙혀서 사용을 하시면 된다.
// 기본적인 인자 값의 타입 지정이 int 등의 primitive 한 자료형이 아닌 *int 등의 포인터 주소값이 기에 , 이중 배열을 이용하고 있다면 d[N] 의 행이 시작하는 곧의 포인터를 기점으로 지정함으로써 그 비교 주소의 시작과 끝에서 최소 및 최대의 값을 인자로 넣어야 한다. 
    
    return 0;
    
    
}
