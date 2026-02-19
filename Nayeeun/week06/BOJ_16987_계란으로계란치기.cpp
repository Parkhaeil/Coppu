#include <iostream>
using namespace std;

int N;
int hp[10];
int weight[10];
int emax = 0;

void egg(int n) {
    if (n == N) {
        int broken = 0;
        for (int i = 0; i < N; i++)
            if (hp[i] <= 0) broken++;

        if (broken > emax) emax = broken;
        return;
    }

    if (hp[n] <= 0) {
        egg(n + 1);
        return;
    }

    bool hit = false;

    for (int i = 0; i < N; i++) {
        if (i == n) continue;
        if (hp[i] <= 0) continue;

        hit = true;

        hp[n] -= weight[i];
        hp[i] -= weight[n];

        egg(n + 1);

        hp[n] += weight[i];
        hp[i] += weight[n];
    }
    if (!hit) egg(n + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> hp[i] >> weight[i];

    egg(0);
    cout << emax;
}
