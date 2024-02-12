#include <iostream>
#include <string>
using namespace std;
void printtime(int time) {
	int time1 = time / 60;//분
	int time2 = time % 60;//초
	if (time1 < 10) {
		cout << "0";
	}
	cout << time1 << ":";
	if (time2 < 10) {
		cout << "0";
	}
	cout << time2 << "\n";
}
int main() {
	int n;
	cin >> n;
	int team;
	int ascore=0, bscore=0, atime=0, btime=0;
	string time;
	string prev = "00.00";

	for (int i = 0; i < n; i++) {
		cin >> team >> time;
		int minute = stoi(time.substr(0, 2)) * 60;
		int second = stoi(time.substr(3, 2));
		int diff = (minute + second) - stoi(prev.substr(0, 2)) * 60 - stoi(prev.substr(3, 2));
		
		if (ascore > bscore) {
			atime += diff;
		}
		else if (ascore < bscore) {
			btime += diff;
		}
		if (team == 1) {
			ascore++;
		}
		if (team == 2) {
			bscore++;
		} 
		prev = time;//마지막 시간 갱신
	}
	int lastgame = 48 * 60 - stoi(prev.substr(0, 2)) * 60 - stoi(prev.substr(3, 2));		
	if (ascore > bscore) {
		atime += lastgame;
	}
	else if (ascore < bscore) {
		btime += lastgame;
	}
	printtime(atime);
	printtime(btime);
	return 0;
}