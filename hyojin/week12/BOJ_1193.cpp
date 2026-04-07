#include<iostream>
#include<vector>
using namespace std;

int main() {
    // 1 -> 1/1
    // 2,3 -> 1/2 , 2/1
    // 4,5,6 -> 3/1 , 2/2, 1/3 
    // 789 10-> 1/4, 2/3, 3/2, 4/1
    int x;
    cin >> x;

    int i=1;
    // 이걸어ㅔ케아노
    while(x>i) {
        x-=i;
        i++;
    }
    int a=x;
    int b=(i+1)-x;
    if (i%2) swap(a,b);
    cout << a << '/' << b;
    // i번째 줄에 있는 분수들은 분자 + 분모 = i+1로 고정
}