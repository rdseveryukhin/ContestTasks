#include <map>
#include <utility>
#include <iostream> 
#include <vector>
using namespace std;

class ArithmeticalProgression {
public:
	map<int, pair<int, int>> map;

	void Add(int first, int diff, int id) {
		map[id] = make_pair(first, diff);
	}

	void Delete(int id) {
		map.erase(id);
	}

	int Get() {
		int key = 0, minVal = 0;
		if (map.begin() != map.end()) {
			key = map.begin()->first;
			minVal = map.begin()->second.first;
		}
		for (auto it = map.begin(); it != map.end(); it++) {
			if (it->second.first < minVal) {
				key = it->first;
				minVal = it->second.first;
			}
		}
		map[key].first += map[key].second;
		return minVal;
	}
};

int main() {
	auto exp = new ArithmeticalProgression();
	int n, operation, val;
	string s;

	cin >> n;
	vector<vector<int>> inputData;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		cin >> operation;
		tmp.push_back(operation);
		switch (operation) {
		case 1:
			for (int j = 0; j < 3; j++) {
				cin >> val;
				tmp.push_back(val);
			}
			break;
		case 2:
			cin >> val;
			tmp.push_back(val);
			break;
		}
		inputData.push_back(tmp);
	}

	for (auto arr : inputData) {
		switch (arr[0]) {
		case 1:
			exp->Add(arr[1], arr[2], arr[3]);
			break;
		case 2:
			exp->Delete(arr[1]);
			break;
		case 3:
			cout << exp->Get() << endl;
			break;
		}
	}
}