#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

const int N = 500;

char MAP[N + 1][N + 1];

struct UESHITA {
	int ue;
	int shita;
};

UESHITA ushi[N + 1][N + 1];

bool func(int x, int y, int K);

int main()
{
	int R, C, K;

	cin >> R >> C >> K;

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			cin >> MAP[y][x];
		}
	}

	for (int x = 1; x <= C; x++) {
		if (MAP[1][x] == 'o'){
			ushi[1][x].ue = 1;
		}
		else {
			ushi[1][x].ue = 0;
		}
	}

	for (int x = 1; x <= C; x++) {
		if (MAP[R][x] == 'o') {
			ushi[R][x].shita = 1;
		}
		else {
			ushi[1][x].shita = 0;
		}
	}

	for (int y = 2; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (MAP[y][x] == 'o') {
				ushi[y][x].ue = ushi[y - 1][x].ue + 1;
			}
			else {
				ushi[y][x].ue = 0;
			}
		}
	}

	for (int y = R - 1; y >= 1; y--) {
		for (int x = 1; x <= C; x++) {
			if (MAP[y][x] == 'o') {
				ushi[y][x].shita = ushi[y + 1][x].shita + 1;
			}
			else {
				ushi[y][x].shita = 0;
			}
		}
	}

	int count = 0;
	for (int y = K; y <= R - K + 1; y++) {
		for (int x = K; x <= C - K + 1; x++) {
			if (ushi[y][x].ue >= K && ushi[y][x].shita >= K) {
				if (func(x, y, K)) {
					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}

bool func(int x, int y, int K)
{
	int p = K - 1;
	for (int i = x - 1; i > x - K; i--) {
		if (ushi[y][i].ue < p || ushi[y][i].shita < p) {
			return false;
		}
		p--;
	}

	p = K - 1;
	for (int i = x + 1; i < x + K; i++) {
		if (ushi[y][i].ue < p || ushi[y][i].shita < p) {
			return false;
		}
		p--;
	}

	return true;
}