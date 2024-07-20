#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};

bool isCongruent(const vector<Point>& base, const vector<Point>& test) {
	vector<int> position = {0, 1, 2, 3};
	do {
		int dx = base[0].x - test[position[0]].x;
		int dy = base[0].y - test[position[0]].y;

		if (all_of(position.begin() + 1, position.end(), [&](int i) {
		return dx == base[i].x - test[position[i]].x &&
			       dy == base[i].y - test[position[i]].y;
		})) {
			return true;
		}
	} while (next_permutation(position.begin(), position.end()));

	return false;
}

int main() {
	vector<Point> base(4);
	for (auto& point : base) {
		cin >> point.x >> point.y;
	}

	int n;
	cin >> n;

	int congruentCount = 0;
	vector<Point> test(4);

	for (int i = 0; i < n; ++i) {
		for (auto& point : test) {
			cin >> point.x >> point.y;
		}
		if (isCongruent(base, test)) {
			++congruentCount;
		}
	}

	cout << congruentCount;
	return 0;
}