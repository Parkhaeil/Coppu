#include <string>
#include <vector>

using namespace std;

string alp = "AEIOU";
int dfs(string current, string word, int& cnt) {
    if(current == word)
        return cnt;
    if(current.length() >= 5)
        return 0;
    for(int i=0; i<5; i++) {
        cnt++;
        int result = dfs(current+alp[i], word,cnt);
        if(result != 0)
            return result;
    }
    return 0;
}

int solution(string word) {
    int cnt = 0;
    return dfs("", word, cnt);
}
