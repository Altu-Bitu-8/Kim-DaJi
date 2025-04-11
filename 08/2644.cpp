#include <iostream>
using namespace std;

const int MAX = 101;
int n, a, b, m;
int graph[MAX][MAX];     // 인접행렬
bool visited[MAX];       // 방문 체크
int result = -1;

void dfs(int current, int count) {
    visited[current] = true;

    if (current == b) {
        result = count;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[current][i] == 1) {
            dfs(i, count + 1);
        }
    }
}

int main() {
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1; // 무방향 그래프프
    }

    dfs(a, 0);

    cout << result;
    return 0;
}
