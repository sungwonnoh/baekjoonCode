#include <iostream>
#include <string>
using namespace std;

string s;
int arr[65][65];

bool check(int x, int y, int n) {//공간내에 전체숫자가 같은지 확인
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void square(int x, int y, int n) {
	if (!check(x, y, n)) {
		cout << "(";
		square(x, y, n / 2);
		square(x, y + n / 2, n / 2);
		square(x + n / 2, y, n / 2);
		square(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}
	else {
		cout << arr[x][y];//전체같은 수일때 0 또는 1 출력
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';//문자를 정수로 변환
		}
	}
	square(0, 0, n);

	return 0;
}