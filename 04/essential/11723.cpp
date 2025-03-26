//정답

#include <iostream>
#include <string>

using namespace std;
int read(int s, string str) {
    int x = 0;
    if (str == "add") {
        //추가한다 -> OR 연산
        cin >> x;
        s |= (1 << x);
    }
    else if (str == "remove") {
        //제거한다 -> 드모르간?!
        //A - B = A - A*B = A(1 - B) = A * ~B
        cin >> x;
        s &= ~(1 << x);
    }
    else if (str == "check") {
        //확인한다 -> AND 연산
        cin >> x;
        if (s & (1 << x)) {
            cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }
    else if (str == "toggle") {
        cin >> x;
        if (s & (1 << x)) {
            s &= ~(1 << x);
        }
        else  s |= (1 << x);
    }
    else if (str == "all") {
        for (int i = 1; i < 21; i++) {
            s |= (1 << i);
        }
    }
    else if (str == "empty") {
        s = 0;
    }
    return s;
}
int main() {
    //시간초과 방지
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    //연산, 출력
    int s = 0;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s = read(s, str);
    }
    return 0;
}