#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if ((int)s[i] < 110) {
				s[i] += 13;
			}
			else {
				s[i] -= 13;
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if ((int)s[i] < 78) {
				s[i] += 13;
			}
			else {
				s[i] -= 13;
			}
		}
	}
	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
	}
	return 0;
}