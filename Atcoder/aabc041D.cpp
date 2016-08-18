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

int ans;

int ARR[N + 1][N + 1];
int narabi[N + 1][N + 1];
bool Visit[N + 1];
bool aruka_naika(int n, int now);
int dfs(int n, int i);

int main()
{
	int n, m;

	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		ARR[y][x] = 1;
		ARR[x][y] = -1;
	}

	int ans = dfs(n, 0);

	cout << ans << endl;

	return 0;
}

int dfs(int n, int i)
{
	int count = 0;
	if (i >= n) {
		return 1;
	}
	else {
		for (int a = 1; a <= n; a++) {
			if (!aruka_naika(n, a) && !Visit[a]) {
				for (int b = 1; b <= n; b++) {
					if (ARR[a][b] == 1) {
						ARR[b][a] = 0;
					}
				}
				Visit[a] = true;
				count += dfs(n, i + 1);
				Visit[a] = false;
				for (int b = 1; b <= n; b++) {
					if (ARR[a][b] == 1) {
						ARR[b][a] = -1;
					}
				}
			}
		}
	}

	return count;
}

bool aruka_naika(int n, int now)
{
	for (int a = 1; a <= n; a++) {
		if (ARR[now][a] == -1) {
			return true;
		}
	}

	return false;
}