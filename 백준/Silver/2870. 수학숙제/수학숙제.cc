#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> num;//숫자를 입력받을 배열
string now;
bool cmp(string a, string b) {//문자열 정렬
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
void findNum(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {//숫자일때
			now += s[i];
		}
		else if (!now.empty()) {
			while (now.length() > 1 && now[0] == '0') {
				now.erase(0, 1);//숫자가 두자리수이상이면서 맨앞자리가 0일때 0삭제
			}
			num.push_back(now);
			now = "";
		}
	}
	if (!now.empty()) {
		while (now.length() > 1 && now[0] == '0') {
			now.erase(0, 1);
		}
		num.push_back(now);
		now = "";
	}
}
int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		findNum(s);
	}
	sort(num.begin(),num.end(),cmp);
	for (auto k : num) {
		cout << k << "\n";
	}

	return 0;
}