#include <iostream>

using namespace std;

const int EARTH = 15;
const int SUN = 28;
const int MOON = 19;

int main() {
    // �Է�
    int e, s, m;
    cin >> e >> s >> m;

    // ����
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
    // ���
    cout << years;
}