#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

const int N = 100;

bool MAP[N + 1][N + 1];
bool Visit[N + 1][N + 1];
int MAP2[N + 1];  //�����܂ł̍ŒZ�̎萔
int MAP3[N + 1];  //�o�H�̐�

int Q[100000];  //���_���i�[
int sp, ep;

bool emp();
void init(int start, int n); //�������֐�
void add(int next);
int toru();

int main()
{
	int n, m, a, b;

	cin >> n >> a >> b >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		MAP[y][x] = true;
		MAP[x][y] = true;
	}

	init(a, n);

	for (int i = 1; i <= n; i++) {
		MAP2[i] = 10000000;
	}
	MAP2[a] = 0;

	while (!emp()) {
		int pt = toru();
		if (pt != b) {
			for (int i = 1; i <= n; i++) {
				if (MAP[pt][i] && !Visit[pt][i]) {
					//�_�C�N�X�g���@�ł��ꂼ��̓_�̍ŒZ�萔�����߂�
					if (MAP2[i] > MAP2[pt] + 1) {
						MAP2[i] = MAP2[pt] + 1;
						add(i);
					}
					Visit[pt][i] = true;
					Visit[i][pt] = true;
				}
			}
		}
	}

	init(a, n);

	while (!emp()) {
		int pt = toru();
		if (pt != b) {
			for (int i = 1; i <= n; i++) {
				if (MAP[pt][i] && !Visit[pt][i]) {
					if (MAP2[pt] + 1 == MAP2[i]) {
						MAP3[i] += MAP3[pt];
						MAP3[i] %= 1000000007;
						add(i);
						Visit[pt][i] = true;
						Visit[i][pt] = true;
					}
				}
			}
		}
	}

	cout << MAP3[b] << endl;

	return 0;
}

bool emp()
{
	return sp == ep;
}

void init(int start, int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Visit[i][j] = false;
		}
	}

	Q[0] = start;
	sp = 0;
	ep = 1;
	MAP3[start] = 1;
}

void add(int next)
{
	Q[ep++] = next;
}

int toru()
{
	return Q[sp++];
}