#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

typedef deque<int> dq;

void rotateClockWise(dq &gear) {
//오른쪽 끝을 왼쪽에 넣는다
int out_in = gear.back();
gear.pop_back();
gear.push_front(out_in);
}
void rotateAntiClockWise(dq &gear) {
//왼쪽 끝을 오른쪽에 넣는다
int out_in = gear.front();
gear.pop_front();
gear.push_back(out_in);
}
bool biteEachOther(const dq &gear_left, const dq &gear_right) {
int st3 = gear_left.at(2);
int st7 = gear_right.at(6);
return st3 != st7;
}

int main() {
int t, k, st, gear_num, rotate_dir;
cin >> t;

vector<dq> gears(t);

for(int i = 0; i < t; i++) {
string line;
cin >> line;
for (char c : line) {
gears[i].push_back(c - '0');
}
}

cin >> k;

for(int i = 0; i < k; i++) {
cin >> gear_num >> rotate_dir;
gear_num--;

// 회전 방향 저장
vector<int> directions(t, 0);
directions[gear_num] = rotate_dir;

// 오른쪽
for(int p = gear_num; p < t - 1; p++) {
if(biteEachOther(gears[p], gears[p + 1])) {
directions[p + 1] = -directions[p];
}
else break;
}

// 왼쪽
for(int p = gear_num; p > 0; p--) {
if(biteEachOther(gears[p - 1], gears[p])) {
directions[p - 1] = -directions[p];
}
else break;
}

// 회전
for(int p = 0; p < t; p++) {
if(directions[p] == 1) rotateClockWise(gears[p]);
else if(directions[p] == -1) rotateAntiClockWise(gears[p]);
}
}

// 출력
int answer = 0;
for(dq gear : gears){
if(gear.at(0) == 1) answer++;
}
cout << answer;
}#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef deque<int> dq;

void rotateAntiClockWise(dq &gear) {
	int out_in = gear.back();
	gear.pop_back();
	gear.push_front(out_in);
}
void rotateClockWise(dq &gear) {
	int out_in = gear.front();
	gear.pop_front();
	gear.push_back(out_in);
}
bool biteEachOther(const dq gear_left, const dq gear_right) {
	int st3 = gear_left.at(2);
	int st7 = gear_right.at(6);
	if(st3 != st7) return true;
	return false;
}
void printAnswer(dq gear){
    cout << gear.at(0);
}
int main() {
    //입력
	int t, k, st, gear_num, rotate_dir;
	cin >> t;

	vector <dq> gears(t);
	
	for(int i=0; i<t; i++) {
		for(int k=0; k<8; k++) {
			cin >> st;
			gears[i].push_front(st);
		}
	}

	cin >> k;
	
	//연산
	for(int i=0; i<k; i++) {
		cin >> gear_num;
		gear_num--;
		cin >> rotate_dir;
		
		if(rotate_dir == 1) {
			rotateClockWise(gears[gear_num]);
		}
		else {
			rotateAntiClockWise(gears[gear_num]);
		}
		
		for(int p=0; p<t-1; p++) {
			while(biteEachOther(gears[p], gears[p+1])) {
				if(rotate_dir == -1) {
					rotateClockWise(gears[gear_num]);
				}
				else {
					rotateAntiClockWise(gears[gear_num]);
				}
			}
		}
	}
	
	//출력
	for(dq gear : gears){
	    printAnswer(gear);
	}
}