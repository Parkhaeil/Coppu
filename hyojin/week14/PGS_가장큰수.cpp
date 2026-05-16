#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for (int i : numbers) {
        v.push_back(to_string(i));
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        return a+b > b+a;
    });
    for (string i : v) {
        answer+=i;
    }
    if (answer[0] == '0') return "0";
    else return answer;
}