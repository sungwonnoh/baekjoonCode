#include <iostream>
using namespace std;
int h, w;
char arr[101][101] = {};//입력받을 문자
int ans[101][101] = { };//출력할 숫자
bool groom() {
	for (int i = 0; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (ans[i][j] == 0) {
				continue;//이미 0일때는 건너뛰기
			}
			else if (ans[i][j - 1] >= 0) {
				ans[i][j] = ans[i][j - 1] + 1;
			}
		}
	}
	return true;
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'c') {
				ans[i][j] = 0;
			}
			else {
				ans[i][j] = -1;
			}
		}
	}
	groom();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}