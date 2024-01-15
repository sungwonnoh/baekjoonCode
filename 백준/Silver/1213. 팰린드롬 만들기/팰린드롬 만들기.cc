#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[26] = {};
bool cannotpalindrome() {//홀수개 존재하는 알파벳이 2개이상이면 불가능
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] % 2 == 1) {
			cnt++;
		}
	}
	return cnt > 1;
}

int main() {
	string s;
	cin >> s;
	string result;

	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'A']++; //문자열에 있는 알파벳 개수세기
	}
	if (cannotpalindrome()) {
		cout << "I'm Sorry Hansoo";
		return 0; //끝
	}
	else {
		for (int i = 0; i < 26; i++) {//앞쪽
			for (int j = 0; j < a[i] / 2; j++) {
				result += i + 'A';
			}
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] % 2) {//중앙
				result += i + 'A';
			}
		}
		for (int i = 25; i >= 0; i--) {//뒤쪽
			for (int j = 0; j < a[i] / 2; j++) {
				result += i + 'A';
			}
		}
		cout << result << endl;
	}

	return 0;
}
