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

const int H = 100;
const int W = 100;

char Pic[H][W];       //���͗p�摜
char ans_Pic[H][W];   //�����摜
char ans2_Pic[H][W];  //������x�߂��ē��͂����摜�ƈ�v���Ă邩���ׂ�

struct POINT {
	int x;
	int y;
};
POINT white[H * W];  //���̍��W���L������
POINT black[H * W];  //���̍��W���L������
int pt_w, pt_b;

//�W�����𒲂ׂ�Ba��b�ɓh��ւ���
void hoko8(int x, int y, char a, char b);
void copy(int w, int h);
bool itti(int w, int h);

int main()
{
	int h, w;

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> Pic[i][j];
			ans_Pic[i][j] = Pic[i][j];
			if (Pic[i][j] == '.') {
				white[pt_w].y = i;
				white[pt_w].x = j;
				pt_w++;
			}
		}
	}

	pt_w--;
	while (pt_w >= 0) {
		hoko8(white[pt_w].x, white[pt_w].y, '#', '.');
		pt_w--;
	}

	//ans_Pic��ans2_Pic�ɃR�s�[
	copy(w, h);

	pt_b--;
	while (pt_b >= 0) {
		hoko8(black[pt_b].x, black[pt_b].y, '.', '#');
		pt_b--;
	}

	if (!itti(w, h)) {
		cout << "impossible" << endl;
	}
	else {
		cout << "possible" << endl;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << ans_Pic[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;
}

void hoko8(int x, int y, char a, char b)
{
	int hoko_x[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int hoko_y[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

	if (a == '#') {
		for (int i = 0; i < 8; i++) {
			if (Pic[y + hoko_y[i]][x + hoko_x[i]] == a) {
				ans_Pic[y + hoko_y[i]][x + hoko_x[i]] = b;
			}
		}
	}

	if (a == '.') {
		for (int i = 0; i < 8; i++) {
			if (ans_Pic[y + hoko_y[i]][x + hoko_x[i]] == a) {
				ans2_Pic[y + hoko_y[i]][x + hoko_x[i]] = b;
			}
		}
	}
}

void copy(int w, int h)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans2_Pic[i][j] = ans_Pic[i][j];
			if (ans_Pic[i][j] == '#') {
				black[pt_b].y = i;
				black[pt_b].x = j;
				pt_b++;
			}
		}
	}
}

bool itti(int w, int h)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (Pic[i][j] != ans2_Pic[i][j]) {
				return false;
			}
		}
	}

	return true;
}