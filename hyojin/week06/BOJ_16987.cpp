#include<iostream>
#include<algorithm>
using namespace std;
int n;
int durability[8];
int weight[8];
int egg=0;

void func(int num) {
    if (num==n) {
        int cnt=0;
        for (int i=0;i<n;i++)
            if (durability[i]<=0) cnt++;
        egg=max(egg,cnt);
        return;
    }
    // => 현재 손에 든 계란이 깨졌을때
    if (durability[num]<=0) {
        func(num+1);
        return;
    }
    bool hit=false;
    for (int i=0;i<n;i++) {
        if (durability[i]>0 && i!=num) {
            hit = true;
            durability[i]-=weight[num];
            durability[num]-=weight[i];
            func(num+1);
            durability[i]+=weight[num];
            durability[num]+=weight[i];
        }
    }
    // => 내구도가 있는 계란이 나밖에 없을때
    if (!hit) func(num+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> durability[i] >> weight[i];
    func(0);
    cout << egg;
}