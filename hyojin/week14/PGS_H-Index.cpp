#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end());
    int mx=0;
    for (int i=0;i<citations.size();i++) {
        // citations[i]=인용횟수
        // h=인용횟수가 기준으로, citations.size()-i=h번 이상 인용된 논문 개수 > 인용횟수
        
        // 10 10 10 일때 citations[0]=10=인용횟수, citations.size()-i=3 으로 3회 이상 인용된 논문이 3편 이상. 횟수>=논문갯수
        // 인용횟수랑 논문갯수 반대로 비교?ㅜ 이해안됨
        if (citations.size()-i<=citations[i]) {
            mx=citations.size()-i;
            break;
        }
    }
    return mx;
}