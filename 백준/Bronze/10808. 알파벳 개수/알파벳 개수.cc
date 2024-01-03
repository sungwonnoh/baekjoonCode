#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int count[26] = {};
	int k;//출력 배열의 인덱스
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			k = (int)s[i] - 97;//각 알파벳의 아스키코드 사용
			count[k] += 1;
		}
	}
	for (int k = 0; k < 26; k++) {
		cout << count[k] << " ";
	}
	
	return 0;
}