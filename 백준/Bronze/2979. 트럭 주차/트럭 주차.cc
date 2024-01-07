#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int arrival, leave;//도착, 출발
	int time[101] = { 0 };//주차한 시간

	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> arrival >> leave;
		if (leave > arrival) {
			for (int j = arrival; j < leave; j++) {
				time[j] += 1; //각 시간대의 차 개수
			}
		}
	}
	int sum = 0;//주차요금
	for (int i = 0; i < 101; i++) {
		if (time[i] == 1) {
			sum += a;
		}
		else if (time[i] == 2) {
			sum += b * 2;//한대당 b원이므로 곱하기 2
		}
		else if (time[i] == 3) {
			sum += c * 3;//한대당 c원이므로 곱하기 3
		}
	}

	cout << sum;

	return 0;
}