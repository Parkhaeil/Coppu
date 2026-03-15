#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b) {
  if (a.length() == b.length()) return a < b;
  return a.length() < b.length();
}

int main(){
  int n;
  cin >> n;
  set<string> unique;
  vector<string> words;

  for (int i = 0;i < n;i++) {
    string word;
    cin >> word;
    unique.insert(word);
  }

  for (string& word : unique) words.push_back(word);

  sort(words.begin(), words.end(), compare);

  for (string& word : words) {
      cout << word << "\n";
  }
  return 0;
}
