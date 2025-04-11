//구현 문제 추가제출출
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef vector<deque<int>> cards;  // 0: 도도, 1: 수연
const int DO = 0, SU = 1; // 도도, 수연 카드 덱 인덱스 

/** 승리 판단하기 */
string judge(cards& deck) {
//카드 수에 따라 승패 판단, 출력값 반환
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();
	//도도의 카드 수, 수연의 카드 수 변수 저장
	if (do_deck > su_deck) {
	//도도의 카드 수가 많으면 도도의 승리
		return "do";
	}
	else if (do_deck < su_deck) {
	//수연의 카드 수가 많으면 수연 승리
		return "su";
	}
	//카드 수가 동일하면 무승부
	return "dosu";
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) {
//플레이어(도도, 수연) 중 한 명의 덱, 그라운드의 덱을 인수로 받는다
	while (!ground.empty()) {
	//그라운드에 카드가 존재하면
		deck.push_back(ground.back());
		//카드를 덱의 뒤에 추가한다
		ground.pop_back();
		//그라운드에서 지운다
	}
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) {
//플레이어가 종을 치면 플레이어들의 덱과 그라운드의 덱의 카드 수가 조정된다.
	groundToDeck(deck[player], ground[!player]);
	// 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); 
	// 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) {
//Q. deck을 사용하지 않는데 인수로 받는 이유?
	if (!ground[DO].empty() && ground[DO].front() == 5) {
	 //도도의 그라운드에 5가 등장, 도도 
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { 
	//수연의 그라운드에 5가 등장, 도도
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { 
	//그라운드에 등장한 카드 합이 5, 수연
		return SU;
	}
	return -1; // 종을 울릴 수 없음
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; 
	// 도도 먼저
	while (m--) {
		ground[turn].push_front(deck[turn].front()); 
		// 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front();
		//덱에서 카드 없애기
		if (deck[turn].empty()) {
		//카드가 없을 경우 게임 종료
			break;
		}

		int bell = whoCanRingTheBell(deck, ground); 
		// 종을 울릴 수 있는 사람 판단
		if (bell != -1) { 
		// 종을 (제대로) 울린 경우
			ringTheBell(bell, deck, ground);
			//그라운드에서 덱으로 카드 이동하기
		}
		turn = !turn; 
		// 차례 바꾸기. 0: 도도, 1: 수연, 0! = 1
	}
	return judge(deck);
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

int main() {
	int n, m, card1, card2;
	//카드 수, 게임 턴 수, 카드 덱 선언
	cards deck(2), ground(2); 
	// 0: 도도, 1: 수연 

	// 입력
	cin >> n >> m;
	while (n--) {
	//카드 가져가기 
		cin >> card1 >> card2;
		deck[DO].push_front(card1);
		//도도
		deck[SU].push_front(card2);
		//수연
	}

	// 출력 & 연산
	cout << game(m, deck, ground);
	

	return 0;
}