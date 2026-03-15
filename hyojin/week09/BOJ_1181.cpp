#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    // 람다 함수로 정렬 커스텀하는 방법 익히기
    sort(v.begin(),v.end(),[](const string& a, const string&b) {
        if (a.length()!=b.length()) return a.length()<b.length();
        return a<b;
    });
    // unique는 뒤로 밀어버린 중복된 요소가 시작되는 위치를 반환
    v.erase(unique(v.begin(),v.end()),v.end());
    // 삭제했으므로 수정된 사이즈만큼만 출력해야함 안그럼 출력초과
    for (int i=0;i<v.size();i++) {
        cout << v[i] << '\n';
    }
}