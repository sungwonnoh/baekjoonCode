#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string p, pile[100];
	cin >> p;
	for (int i = 0; i < n; i++) {
		cin >> pile[i];
	}
	int idx = p.find('*');
	string frontp = p.substr(0, idx);
	string backp = p.substr(idx + 1);
	int fsize = frontp.length();//size와 length차이
	int bsize = backp.length();

	for (int i = 0; i < n; i++) {
		if (fsize + bsize > pile[i].length()) {
			cout << "NE" << endl;
		}
		else {
			if (frontp == pile[i].substr(0, fsize) && backp == pile[i].substr(pile[i].length() - bsize )) {
				cout << "DA" << endl;
			}
			else {
				cout << "NE" << endl;
			}
		}
	}

	return 0;
}