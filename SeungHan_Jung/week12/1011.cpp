#include <bits/stdc++.h>
using namespace std;

// (1+1) -> (1+2+1) -> (1+2+2+1) -> (1+2+3+2+1)
// 잠시만 그러면 1+2+... + 100 , 100+...+2+1 사이에 거리 딱 1 남거나 그러면 어떡하지
// 여기서 이런 구간 (1+1) , (1+2+2+1) 이런 곳 먼저 찾은 다음에 그 안에서 한번만 더 나누면 될 것 같은데
// 그 구간을 찾는 방법 -> 어떤 수 n 에 대해 , dist 가 n(n+1)초과 , (n+1)(n+2) 이하가 되는 n 을 찾아야 함 
// 그 n 을 찾으면 , 2n + 1번 또는 2n+2 번 그 엔진을 가동시키는 룰이 형성됨.
// 그 중간에서 , dist 가 n(n+1) + (n+1) 즉 (n+1)^2 보다의 큰지 작은지를 가지고 최종 엔진 가동횟수를 구함.
// 잠시만 2^31 이면 일단 long long 으로 타입을 설정하고 가야겠네

int main(){
    int N,dist;
    long long x,y;
    cin >> N;
    std::queue<pair<long long,long long>> input;
    while(N--){
        int start,back;
        cin >> start >> back;
        input.push({start,back});
    }
    int count = 0;
    while(!input.empty()){
        //cout << "count :" << count++ << "\n";
        long long x = input.front().first;
        long long y = input.front().second;
        input.pop();
        dist = y-x;
        if(dist == 1){
            cout << 1 << "\n";
            continue;
        }else if(dist == 2){
            cout << 2 << "\n";
            continue;
        }else if(dist == 3 || dist ==4){
            cout << 3 << "\n";
            continue;
        }else if(dist == 5){
            cout << 4 << "\n";
            continue;
        }else if(dist == 6){
            cout << 4 << "\n";
            continue;
        }
        long long i = 2;
        if(dist >= 7){
        while(1){
        // 1+2+1+2+1 , 1+2+2+2+1 , 1+2+3+2+1 여기까지만 보고 바로
        // 1+2+3+3+2+1 로 넘어가버림... 
            if(dist > i*(i+1) && dist <= (i+1)*(i+2)){ // ex. 1+1 일수도 , 1+1+1 일수도 , 1+2+1 일수도 , 1+2+1+1이 될 수도 , 1+2+2+1 일수도 있지
                          // 근데 1 + 2 + 1 에서 못 끝나고 그 사이에 1이던 , 2던 끼는 순간 사실상 엔진 점화 횟수는 똑같이 1회 늘어나는거임
            if(dist <= (i+1)*(i+1)){ 
                // c++에서는 그냥 ** 자체가 문법 오류고 , ^ 는 xor 연산자라서 그냥 곱하는 수를 * 기준으로 왼쪽 한번 오른쪽 한번 그렇게 둬야 함
                cout << 2*i+1 << "\n";
                break;
            }else{
                cout << 2*(i+1) << "\n";
                break;
                }
            }
            i++;
        }
        }
    }
    return 0;
}
