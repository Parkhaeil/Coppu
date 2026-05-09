#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0;
    int h = 0;

    for (int i=0;i<sizes.size();i++) {
        int big = max(sizes[i][0], sizes[i][1]);
        int small = min(sizes[i][0], sizes[i][1]);

        w = max(w, big);
        h = max(h, small);
    }
    return w * h;
}
