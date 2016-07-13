#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

//ƒWƒƒƒ“ƒv‚µ‚½‰ñ”
int kaisu;

void func(int x, int y, int g_x, int g_y, int n, int i);

int main()
{
	int n, d, x, y;

	cin >> n >> d >> x >> y;

	if (x % d != 0 || y % d != 0) {
		printf("%d\n", 0);
	}
	else {
		x /= d;
		y /= d;
	}

	func(0, 0, x, y, n, 0);

	double ans = kaisu / pow(4, n);

	printf("%lf\n", ans);

	return 0;
}

void func(int x, int y, int g_x, int g_y, int n, int i)
{
	if (x == g_x && y == g_y && i == n) {
		kaisu++;
	}
	else if (i < n) {
		func(x + 1, y, g_x, g_y, n, i + 1);
		func(x - 1, y, g_x, g_y, n, i + 1);
		func(x, y + 1, g_x, g_y, n, i + 1);
		func(x, y - 1, g_x, g_y, n, i + 1);
	}
}