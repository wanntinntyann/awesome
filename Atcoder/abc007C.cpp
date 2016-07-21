#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

const int N = 50;

char MAP[N + 1][N + 1];

struct PATH{
	int mae_x;
	int mae_y;
	int x;
	int y;
	int len;
};
PATH Q[10000];
int sp, ep;

void init(int y, int x);
void set(int y, int x, PATH p);
PATH del();
bool emp();
void tansaku(int gy, int gx, PATH p);

int main()
{
	int row, col;
	int sy, sx, gy, gx;
	cin >> row >> col >> sy >> sx >> gy >> gx;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> MAP[i][j];
		}
	}

	init(sy, sx);
	PATH p = Q[0];
	tansaku(gy, gx, p);


	return 0;
}

void init(int y, int x)
{
	Q[0].mae_x = -1;
	Q[0].mae_y = -1;
	Q[0].y = y;
	Q[0].x = x;
	Q[0].len = 0;
	ep = 1;
}

void set(int y, int x, PATH p)
{
	Q[ep].len = p.len;
	Q[ep].mae_y = p.y;
	Q[ep].mae_x = p.x;
	Q[ep].y = y;
	Q[ep].x = x;
	Q[ep].len++;
	ep++;
}

PATH del()
{
	//cout << Q[sp].x << "," << Q[sp].y << endl;
	return Q[sp++];
}

bool emp()
{
	return sp == ep;
}

void tansaku(int gy, int gx, PATH p)
{
	if (p.y == gy && p.x == gx) {
		cout << ep << endl;
		cout << p.len << endl;
	}
	else if(!emp()){
		p = del();
		if (MAP[p.y + 1][p.x] == '.' && (p.y + 1 != p.mae_y || p.x != p.mae_x)) {
			set(p.y + 1, p.x, p);
		}
		if (MAP[p.y - 1][p.x] == '.' && (p.y - 1 != p.mae_y || p.x != p.mae_x)) {
			set(p.y - 1, p.x, p);
		}
		if (MAP[p.y][p.x + 1] == '.' && (p.y != p.mae_y || p.x + 1 != p.mae_x)) {
			set(p.y, p.x + 1, p);
		}
		if (MAP[p.y][p.x - 1] == '.' && (p.y != p.mae_y || p.x - 1 != p.mae_x)) {
			set(p.y, p.x - 1, p);
		}

		tansaku(gy, gx, p);
	}
}