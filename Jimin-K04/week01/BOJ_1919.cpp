#include <iostream>
#include <string>
#include <cmath>
// 애너그램 불가능한 경우는 없다고 가정 0
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    int cnt = 0;
    int a[26] = {};
    for (auto c : s1) a[c - 'a']++;
    for (auto c : s2) a[c - 'a']--;
    for (int i : a) if (i != 0) cnt += abs(i);
    cout << cnt;
}