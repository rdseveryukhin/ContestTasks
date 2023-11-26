#include <string>
#include <utility>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;

struct comp {
	bool operator () (const pair<string, int> x, const pair<string, int> y) const {
		if (x.second != y.second) return x.second < y.second;
		return x.first < y.first;
	}
};

int main() {
	ios::sync_with_stdio(0);

	ifstream fin("testData.txt");
	ofstream fout("testRes.txt", ios::app);

	unordered_map<string, int> exp;
	map<pair<string, int>, bool, comp> team;
	auto iter = team.begin();
	pair<string, int> key;

	int prev_sum = 0, prev_time = 0, time = 0, n;
	string name;

	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> name >> time;

		key = make_pair(name, exp[name]);
		if (exp[name] != 0) iter = team.find(key);

		int sum = prev_sum + (time - prev_time) * team.size();

		if (exp[name] == 0 || iter == team.end()) {
			key.second = time - exp[name];
			team.emplace(key, true);
			exp[name] = key.second;
			sum += time - key.second;
		}
		else {
			exp[iter->first.first] = time - iter->first.second;
			sum -= time - iter->first.second;
			team.erase(iter);
		}

		int worker = time - team.begin()->first.second;

		fout << team.begin()->first.first << ' ' << sum - worker - worker << '\n';

		prev_sum = sum;
		prev_time = time;
	}
}