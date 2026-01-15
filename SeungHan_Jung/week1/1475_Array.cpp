#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[10] = {}; // {0} , {0,} 등도 가능
    int N;
    cin >> N;
    
    while(N != 0){
        
        if(N % 10 == 6 || N % 10 == 9){
            if(arr[6] == arr[9]) arr[6]++;
            else arr[9]++;
        }else{
            arr[N % 10]++;
        }
        N /= 10;
    }
    
    int max = arr[0];
    for(int v : arr){
        if(v > max) max = v;
    }
    
    cout << max;
    return 0;
}

// 1. 6 과 9 를 같은 수로 취급한다고 할때 , 0~9 의 인덱스들 중에서 6 , 9 에 할당된 그 수가 같은 경우에는 
// 6부터 늘리고 아닌 경우에 9 를 늘리는 방식처럼 , 수를 늘리는 그 순서를 정해버리는 경우 좋더라
// 그리고 쌍 단위로 하나가 취급되는 그러한 문제에서 총 필요한게 몇개인가를 구하기 위해 max 를 사용하는 것 좋더라
