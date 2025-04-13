//추가제출

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix; 
// 바둑판을 저장하는 2차원 (동적) 배열
const int SIZE = 20, EMPTY = 0; 
// 바둑판 사이즈, 비어있는 상태

const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};
// 방향에 따른 좌표 증가량
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의

bool isValid(matrix &board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);\
    // 돌이 바둑판 범위 안에 있는가?
    // 돌이 연결되어 있는가? (색 조건)
}

bool checkWin(matrix &board, int x, int y) {
    int color = board[x][y]; 
    // 기준 색

    // 4 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    // cnt: 같은 방향에 놓인 같은 색 돌의 수
        int prev_x = x - dx[idx], prev_y = y - dy[idx];
        // 방향 기준 이전 바둑알 좌표 저장
        int next_x = x + dx[idx], next_y = y + dy[idx];
        // 방향 기준  다음 바둑알 좌표 저장
        

        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 
        // -> 여섯 알 이상 놓이는 경우를 선제외하기 위함
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        while (isValid(board, next_x, next_y, color) && cnt < 6) {
        // for문에서 확인 중인 방향을 따라 최대 5회 바둑알 연속성 검사 
		        next_x += dx[idx];
		        // 다음에 while문에서 검사할 바둑알의 x좌표
            next_y += dy[idx];
             // 다음에 while문에서 검사할 바둑알의 x좌표
            cnt++;
             // (방금 while문에서 검사한) 바둑알이 연속이면 cnt++       
        }
        // cnt가 5일 때만 true 리턴, 바둑알이 연속으로 5알 놓이는 경우
        if (cnt == 5) {
            return true;
        }
    }
    return false;
    //cnt가 5 미만일 경우 false 리턴
}

int main() {
    // 입력
    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판 생성, 0 초기화
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j];

    // 연산 및 출력
    for (int y = 1; y < SIZE; y++) {
        for (int x = 1; x < SIZE; x++) {
            // 빈 칸이면 패스
            if (board[x][y] == EMPTY) {
                continue;
            }
            // 해당 좌표(x, y)부터 연속적으로 5알이 놓였다면
                       if (checkWin(board, x, y)) {
                cout << board[x][y] << '\n'
                 // 승부 결과와
                     << x << ' ' << y;
                 // 가장 왼쪽 위에 놓인 바둑알 출력하기
                return 0;
                // 흑/백 중 하나가 승리하였음 -> 종료
            }
        }
    }
    cout << 0;
    // 무승부 -> 0 출력, 종료
    return 0;
}