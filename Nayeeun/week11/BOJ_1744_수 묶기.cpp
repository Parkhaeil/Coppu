#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> num, trash;
    int one = 0, zero = 0;

    while(n--) {
        int x;
        cin >> x;

        if (x > 1) num.push_back(x);
        else if (x == 1) one++;
        else if (x == 0) zero++;
        else trash.push_back(x);
    }

    sort(num.begin(), num.end(), greater<int>());
    sort(trash.begin(), trash.end());

    int sum = 0;
    for (int i = 0; i < num.size(); i += 2) {
        if (i + 1 < num.size())
            sum += num[i] * num[i + 1];
        else
            sum += num[i];
    }
    for (int i = 0; i < trash.size(); i += 2) {
        if (i + 1 < trash.size())
            sum += trash[i] * trash[i + 1];
        else {
            if (zero == 0)
                sum += trash[i];
        }
    }
    sum += one;
    cout << sum;
}
