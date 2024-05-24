#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string num;
	int result = 0;
	bool isMinus = false;//마이너스 뒤로 괄호묶어서 빼기

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (isMinus) {
				result -= stoi(num);
				num = "";
			}
			else {
				result += stoi(num);
				num = "";
			}
		}
		else {
			num += s[i];
		}
		if (s[i] == '-') {
			isMinus = true;
		}
	}
	cout << result;
	return 0;
}