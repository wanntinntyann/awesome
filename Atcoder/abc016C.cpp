#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

const int N = 10;
const int M = N * (N - 1) / 2;

//���ݒ��ڂ��Ă�F�B
int tomo1;  

int tomo[N + 1][N + 1];  //�F�B�̊֌W��\���אڍs��

//�F�B�̃��X�g�B�F�B�̗F�B�������ɏ���Ă����ꍇ�̓J�E���g���Ȃ��B
bool tomodachi[N + 1][N + 1];

//�F�B�̗F�B�̃��X�g
bool tomotomo[N + 1];

//�F�B�̗F�B�̐�
int tomo2[N + 1];


void func(int y, int count);

int main()
{
	int N, M;

	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		tomo[x][y] = 1;
		tomo[y][x] = 1;
	}

	func(1, 1);
	for (int i = 1; i <= N; i++) {
		cout << tomo2[i] << endl;
	}

	return 0;
}

void func(int y, int count)
{
	switch (count) {
	case 1:
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tomo[i][j] == 1) {
					tomo1 = i;

					//�F�B�𒲂ׂ�
					for (int i = 1; i <= N; i++) {
						if (tomo[tomo1][i] == 1) {
							tomodachi[tomo1][i] = true;
						}
					}
					func(j, count + 1);
				}
			}
			
			//���̐l������̂�tomotomo�z������Z�b�g
			for (int i = 1; i <= N; i++) {
				tomotomo[i] = false;
			}
		}
		break;
	case 2:
		for (int i = 1; i <= N; i++) {
			if (tomo[y][i] == 1 && i != tomo1 && tomodachi[tomo1][i] == false && tomotomo[i] == false) {
				tomotomo[i] = true;
				func(i, count + 1);
			}
		}
		break;
	case 3:
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			if (tomo[y][i] == 1 && i == tomo1) {
				flag = true;
			}
		}
		if (flag == false) {
			tomo2[tomo1]++;
		}
		break;
	}
}