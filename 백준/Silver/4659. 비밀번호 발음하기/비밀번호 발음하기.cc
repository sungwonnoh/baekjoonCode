#include <iostream>
#include <string>
using namespace std;

bool password(string s) {
	int consonant = 0, vowel = 0;
	bool morevowel = false;//조건1 모음이 있는지 확인
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			vowel++;
			morevowel = true;
			consonant = 0;
		}
		else {
			consonant++;
			vowel = 0;
		}
		if (i < s.length() - 1 && (s[i] == s[i + 1])) {
			if (s[i] != 'e' && s[i + 1] != 'o') {//ee나 oo만 가능
				return false;
			}
		}
		if (vowel >= 3 || consonant >= 3) {
			return false;//조건2 연속적으로 3개이상인지 확인
		}
	}
	return morevowel;
}
int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "end") {
			break;
		}
		cout << "<" << s << "> is ";
		if (password(s)) {
			cout << "acceptable.\n";
		}
		else {
			cout << "not acceptable.\n";
		}
	}
	return 0;
}