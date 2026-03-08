 //사실 가능한 모든 경우의 수들을 다 줄 세워서 경우의 수 풀 듯이 풀면 가능하긴 한데
//dfs 를 통해서 푸는게 이게 진정한 dfs 인지도 모르겠고 , 시간복잡도 상으로 더 나은 선택인지도 몰겠긴함.

#include<iostream>
#include<vector>
using namespace std;

int MAX = -1000000000;
int MIN = 1000000000;

int Operator[4]; // + , - , x , / 순이다.
vector<int> numbers;
int N;

void dfs(int plus , int minus , int multiple , int divide , int x , int sum){
    // sequence number 가 연산자의 수랑 같으면 이제 끝
    if(x == N-1){ //   x <= N-1 아님 제발 
        if(sum > MAX) MAX = sum;
        if(sum < MIN) MIN = sum;
    }
    
    // 첫번째 단계에서는 여기부터가 사실상 첫 시작
    if(plus > 0) dfs(plus-1,minus,multiple,divide,x+1,sum+numbers[x+1]);
    if(minus > 0) dfs(plus,minus-1,multiple,divide,x+1,sum-numbers[x+1]);
    if(multiple > 0) dfs(plus,minus,multiple-1,divide,x+1,sum*numbers[x+1]);
    if(divide > 0) dfs(plus,minus,multiple,divide-1,x+1,sum/numbers[x+1]);
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int m;
        cin >> m;
        numbers.push_back(m);
    }
    for(int j = 0 ; j < 4 ; j++){
        cin >> Operator[j];
    }
    dfs(Operator[0],Operator[1],Operator[2],Operator[3],0,numbers[0]);
    cout << MAX << '\n' << MIN;
    return 0;
}

