#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int hour_len = to_string(n - 1).length();
	int minute_len = to_string(m - 1).length();
	int len = max(hour_len, minute_len);

	int count = 0;

	int val1 = (n <= m ? n : m);
	int val2 = (val1 == n ? m : n);

	for (int i = 0; i < val1; i++) {
		string tmp = to_string(i);
		tmp.insert(tmp.begin(), len - tmp.length(), '0');
		reverse(tmp.begin(), tmp.end());
		int j = stoi(tmp);
		if (j < val2) count++;
	}

	cout << count;
}