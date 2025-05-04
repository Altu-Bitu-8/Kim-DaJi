#include <iostream>  
#include <deque>     

using namespace std;

struct info { // 각 칸의 내구도와 로봇 존재 여부를 저장하는 구조체
    int power;      // 내구도
    bool is_on = false; // 로봇 존재 여부
};

// 벨트를 한 칸 회전
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back()); // 마지막 칸을 맨 앞에 삽입
    belt.pop_back();              // 마지막 칸 제거
    belt[n - 1].is_on = false;    // 내리는 위치에 있는 로봇 제거
}

// 로봇을 조건에 따라 한 칸 이동
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // n-2부터 0까지 역순 순회
        if (belt[i].is_on && !belt[i + 1].is_on && (belt[i + 1].power >= 1)) {
            belt[i].is_on = false;      // 현재 위치 로봇 제거
            belt[i + 1].is_on = true;   // 다음 위치에 로봇 이동
            belt[i + 1].power--;        // 내구도 감소
        }
    }
    belt[n - 1].is_on = false; // 내리는 위치 로봇 제거
}

// 올리는 위치에 로봇을 올림림
void putRobot(deque<info> &belt) {
    if (belt[0].power >= 1) {     // 올리는 위치(0번)의 내구도가 1 이상이면
        belt[0].is_on = true;     // 로봇 올림
        belt[0].power--;          // 내구도 감소
    }
}

// 내구도가 0인 칸의 수가 K 이상인지 확인인
bool checkFinish(deque<info> &belt, int n, int k) {
    int cnt = 0; // 내구도 0인 칸 수
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            cnt++; // 내구도 0인 칸 개수 증가
        }
    }
    return cnt >= k; // 내구도 0인 칸이 k 이상이면 true
}

// 전체 시뮬레이션을 진행하고 종료 시 step 반환
int solution(deque<info> &belt, int n, int k) {
    int step = 1; // 현재 단계 수 
    while (true) {
        rotateBelt(belt, n);    // 1. 벨트 회전
        moveRobot(belt, n);     // 2. 로봇 이동
        putRobot(belt);         // 3. 로봇 올리기
        if (checkFinish(belt, n, k)) { // 4. 종료 조건 확인
            return step; // 조건 만족하면 현재 단계 반환
        }
        step++; // 단계 수 증가
    }
}

int main()
{
    ios::sync_with_stdio(false); // 입출력 동기화 비활성화
    cin.tie(NULL);               // cin과 cout의 묶음을 해제
    cout.tie(NULL);              // cout 묶음 해제

    int n, k; // n: 벨트 절반 길이, k: 내구도 0인 칸 최대 허용 수
    cin >> n >> k;
    deque<info> belt(2 * n); // 총 2n 길이의 벨트 생성

    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power; // 각 칸의 초기 내구도 입력
    }

    cout << solution(belt, n, k); // 결과 출력
}
