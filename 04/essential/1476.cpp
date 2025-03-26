#include <iostream>

using namespace std;

const int EARTH = 15;
const int SUN = 28;
const int MOON = 19;

int main() {
    // 입력
    int e, s, m;
    cin >> e >> s >> m;

    // 연산
    int years = 0;
    while (true) {
        if (e == s && s == m) {
            years += e;
            break;
        }
        e--;
        s--;
        m--;
        if (e == 0) e = EARTH;
        if (s == 0) s = SUN;
        if (m == 0) m = MOON;
        years++;
    }
    // 출력
    cout << years;
}