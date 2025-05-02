#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N;
int W[10][10];// 비용
bool visited[10];// 도시 방문 
int ans = INF;// 최소 비용

void dfs(int start, int current, int cost, int count) {
    if (count == N && W[current][start] != 0) {
        ans = min(ans, cost + W[current][start]);
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!visited[next] && W[current][next] != 0) {
            visited[next] = true;
            dfs(start, next, cost + W[current][next], count + 1);
            visited[next] = false; //백트래킹
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    for (int i = 0; i < N; i++) {
        fill(visited, visited + N, false);
        visited[i] = true;
        dfs(i, i, 0, 1);
    }

    cout << ans << endl;
    return 0;
}
