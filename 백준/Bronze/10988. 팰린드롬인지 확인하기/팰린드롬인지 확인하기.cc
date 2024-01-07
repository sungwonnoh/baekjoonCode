#include <iostream>
#include <string>
using namespace std;

bool palindrome(string str) {
	int s = str.length(); //길이
	for (int i = 0; i < s / 2; i++) {
		if (str[i] != str[s - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	string str;
	cin >> str;

	if (palindrome(str)) {
		cout << "1";
	}
	else {
		cout << "0";
	}

	return 0;
}