#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    int x;
    cin >> x;
    
    sort(a,a+n); // 반열린구간 -> sort(a,a+(n-1)) 이 아닌이유
    
    int left = 0;
    int right = n-1; // 인덱스
    int answer = 0;
    
    while(left < right){
        if(a[left] + a[right] > x){
            right--;
        }else if(a[left] + a[right] < x){
            left++;
        }else{
            answer++;
            left++;
            right--;
        }
    }
    
    cout << answer;
    
    return 0;
}

// 어떤 정수들의 array 를 받는다고 할떄 그 안에서 뭐 2개의 합이 뭐 어떤 조건을 만족하는
// 그런 유형의 경우 , 공통의 시작접을 2개 잡고 시작하는 느낌
