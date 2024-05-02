#include <iostream>
#include <cmath>
using namespace std;

int inout(int x1, int y1, int x2, int y2, int cx, int cy, int r) {
	if (pow(cx - x1, 2) + pow(cy - y1, 2) <= r * r) {//시작점 안
		if (pow(cx - x2, 2) + pow(cy - y2, 2) > r * r) {//도착점 밖
			return 1;
		}
	}
	if (pow(cx - x2, 2) + pow(cy - y2, 2) <= r * r) {
		if (pow(cx - x1, 2) + pow(cy - y1, 2) > r * r) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int t, n;
	int cnt = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		cnt = 0;
		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			cnt += inout(x1, y1, x2, y2, cx, cy, r);
		}
		cout << cnt << "\n";
	}

	return 0;
}