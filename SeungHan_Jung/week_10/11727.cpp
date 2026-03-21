// 전형적인 dp 문제가 아닐까 
// n 이라는 수를
// 1. 2x(1x2) + way(n-2) 
// 2. 1x(2x1) + way(n-1)
// 3. 1x(2x2) + way(n-2)
// 이런 3가지의 경우의 수로 나눠서 구할 수 있는 것 같다.
// 그럼 결국 우리에게 필요한 것은 1000보다 조금 큰 길이의 1차원 배열이겠군
   
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    int way[1004];
    way[0] = 0;
    way[1] = 1;
    way[2] = 3;
    
    for(int i = 3 ; i <= N ; i++){
        way[i] = (2*way[i-2] + way[i-1]) % 10007;
        // 내가 문제를 잘 못 알아들은 거임 뭐임?
    }
    
    cout << way[N];
}
