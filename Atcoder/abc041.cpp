#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

const int N = 16;

int ARR[N + 1][N + 1];
bool Visit[N + 1][N + 1];
bool flag[N + 1];
int gomi[N + 1];
int pt;

struct RUN {
	int val[N + 1];
	int len;
};

RUN Q[1000];
int Q_pt;

bool aruka_naika(int a, RUN pt);
void add(int a, int b);
void show(RUN pt);

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> y >> x;

		ARR[y][x] = 1;
		ARR[x][y] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!Visit[i][j]) {
				if (ARR[i][j] == 1) {
					flag[i] = true;
					add(i, j);
					//	cout << i << j << endl;
					Visit[i][j] = true;
					Visit[j][i] = true;
				}
				else if (ARR[i][j] == -1) {
					flag[j] = true;
					add(j, i);
					//cout << j << i << endl;
					Visit[i][j] = true;
					Visit[j][i] = true;
				}
			}
		}
		if (flag[i] == false) {
			gomi[pt++] = i;
		}
	}

	int PT = pt;
	while (Q_pt > 0) {
		RUN run = Q[--Q_pt];
		while (pt > 0) {
			pt--;
			if (!aruka_naika(gomi[pt], run)) {
				run.val[run.len] = gomi[pt];
				show(run);
			}
		}
		pt = PT;
	}

	return 0;
}

bool aruka_naika(int a, RUN pt)
{
	for (int i = 0; i < pt.len; i++) {
		if (pt.val[i] == a) {
			return true;
		}
	}

	return false;
}

void add(int a, int b)
{
	Q[Q_pt].val[Q[Q_pt].len] = a;
	Q[Q_pt].len++;
	Q[Q_pt].val[Q[Q_pt].len] = b;
	Q[Q_pt].len++;
	Q_pt++;
}

void show(RUN pt)
{
	for (int i = 0; i <= pt.len; i++) {
		cout << pt.val[i];
	}
	cout << endl;
}