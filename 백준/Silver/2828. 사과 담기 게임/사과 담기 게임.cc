#include <iostream>
using namespace std;

int main() {
	int n, m, j, apple;
	cin >> n >> m;
	cin >> j;
	int start = 1;
	int end = m;
	int cnt = 0;
	for (int i = 0; i < j; i++) {
		cin >> apple;
		if (apple < start) {//바구니보다 왼쪽
			cnt += start - apple;
			end -= (start - apple);
			start = apple;
		}
		if (apple > end) {//바구니보다 오른쪽
			cnt += apple - end;
			start += (apple - end);
			end = apple;
		}
	}
	cout << cnt;

	return 0;
}