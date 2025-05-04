#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;
int op[4];
int maxResult = -1e9;
int minResult = 1e9;

void dfs(int idx, int current) {
    if (idx == N) {
        maxResult = max(maxResult, current);
        minResult = min(minResult, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            int next = current;

            if (i == 0) next += numbers[idx];// 덧셈
            else if (i == 1) next -= numbers[idx];// 뺄셈
            else if (i == 2) next *= numbers[idx];// 곱셈
            else if (i == 3) { // 나눗셈
                if (next < 0)
                    next = -(-next / numbers[idx]);
                else
                    next = next / numbers[idx];
            }

            dfs(idx + 1, next);
            op[i]++; //백트레킹
        }
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];
    for (int i = 0; i < 4; i++) cin >> op[i];

    dfs(1, numbers[0]);

    cout << maxResult << '\n' << minResult << '\n';
    return 0;
}