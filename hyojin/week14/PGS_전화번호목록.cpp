#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<string> set;

bool solution(vector<string> phone_book)
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        set.insert(phone_book[i]);
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        string s = "";
        // 맨 마지막 문자 미포함시켜서 자기자신 find하지 않도록 해야함
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            s += phone_book[i][j];
            // prefix가 set 안에 없으면 s.end() 반환
            if (set.find(s) != set.end())
                return false;
        }
    }
    return true;
}