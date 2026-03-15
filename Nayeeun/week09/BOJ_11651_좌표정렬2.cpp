#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};

bool compare(Point& a, Point& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int n;
	cin >> n;
	Point points[100000];

	for (int i = 0; i < n; i++)
		cin >> points[i].x >> points[i].y;

	sort(points, points + n, compare);
	for (int i = 0; i < n; i++)
		cout << points[i].x << " " << points[i].y << "\n";
	return 0;
}
