/*
pair의 정렬 순서는 first를 먼저 비교하기 때문에 둘의 자리를 바꿔서 
집어넣은 후 정렬하면 된다고함..
*/
#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> p[100001];
#define x first
#define y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // second에 x좌표들 넣고 first에 y좌표들 입력받아 y 기준 정렬
    for (int i=0;i<n;i++) {
        cin >> p[i].y >> p[i].x;
    }
    sort(p,p+n);
    for (int i=0;i<n;i++) {
        cout << p[i].y << ' ' << p[i].x << '\n';
    }
}