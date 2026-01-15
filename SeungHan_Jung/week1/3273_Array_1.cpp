// sort의 과정 없이 시간 복잡도를 O(n)까지 줄이는 코드
// sort 가 들어가면 아무리 빨라도 O(nlogn) 까지 늘어남
#include <iostream>
#include <algorithm>
using namespace std;
int a[100005]; // 입력으로 들어올 수 있는 배열의 최대 인자 수 : 10005 -> 입력을 받기 위한 배열
bool exist[2000005]; // 입력으로 들어올 수 있는 가장 큰 수 : 2000005 
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    int x;
    cin >> x; // target
    
    int answer = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(x-a[i] > 0 && exist[x-a[i]] == true){
            answer++;
        }
        exist[a[i]] = true;
    }    
    
    cout << answer;
    return 0;
}
