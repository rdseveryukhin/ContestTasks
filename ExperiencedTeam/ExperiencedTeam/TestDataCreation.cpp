//#include <fstream>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int getRandomNumber(int min, int max) {
//	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
//	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
//}
//
//int main() {
//	ofstream file("testData.txt", ios::app);
//	int min = 0, max = 0;
//	string str = "Name";
//	for (int i = 0; i < 300000; i++) {
//		if (!file.is_open()) break;
//		max = min + 3;
//		int val = getRandomNumber(min, max);
//		int let = getRandomNumber(97, 122);
//		file << str + (char)let << ' ' << val << endl;
//		min = val;
//		cout << i << endl;
//	}
//	file.close();
//}