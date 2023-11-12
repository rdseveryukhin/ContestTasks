#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	string str;
	stringstream res;
	string s;
	int count = 0;

	getline(cin, str);
	while (!str.empty()) {
		int n = str.length();

		for (int i = 0; i < n; i++) {
			if (str[i] == ' ' || str[i] == '\t') {
				if (i == 0) {
					while (str[i] == ' ' || str[i] == '\t') i++;
					if (str[i] != ')' && count != 0 && (!s.empty() && s[s.length() - 1] != '(')) res << ' ';
				}
				else {
					if (s == "in") {
						while (str[i] != '(') i++;
						int braces = 1;
						res << ' ' << str[i++];
						while (!str.empty()) {
							while (i < n && (braces != 1 || str[i] != ')')) {
								if (str[i] == '(') braces++;
								else if (str[i] == ')') braces--;
								i++;
							}
							if (!(i < n)) {
								getline(cin, str);
								i = 0;
								n = str.length();
							}
							else break;
						}
						res << "...";
					}
					else {
						while (i < n && (str[i] == ' ' || str[i] == '\t')) i++;
						if (i < n && str[i] != ')' && (!s.empty() && s[s.length() - 1] != '(')) res << ' ';
					}
				}
				s.clear();
			}
			else {
				if (i == 0) {
					if ((!s.empty() && s[s.length() - 1] != '(') && str[i] != ')' && count != 0) res << ' ';
					s.clear();
				}
			}

			if (i >= n) break;

			char c = tolower(str[i]);
			if (str[i] == '\"') {
				while (str[++i] != '\"');
				c = '?';
			}
			res << c;
			s += c;
		}
		count++;
		getline(cin, str);
	}

	cout << res.str();
}