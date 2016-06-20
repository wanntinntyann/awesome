#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1000;

//����������W
struct ONA {
	int x;
	int y;
};
ONA *ona;
int main() 
{
	int T;			//�ړ��ɂ�����������
	int V;			//�ړ����̑��x(����)
	int n;			//���̐�
	int a1, a2;     //�ړ��O�̍��W
	int b1, b2;     //�ړ���̍��W
	int x, y;

	cin >> a1 >> a2 >> b1 >> b2 >> T >> V >> n;

	//���̍��W���i�[���邽�߂̔z����m��
	ona = new ONA[n];

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		ona[i].x = x;
		ona[i].y = y;
	}

	//�ړ��\�ȋ���
	double kyori = T * V;
	double ona_kyori = 0;
	for (int i = 0; i < n; i++) {
		int a = ona[i].x - a1;
		int b = ona[i].y - a2;
		ona_kyori = sqrt(a * a + b * b);
		a = b1 - ona[i].x;
		b = b2 - ona[i].y;
		ona_kyori += sqrt(a * a + b * b);
		if (ona_kyori <= kyori) {
			cout << "YES" << endl;
			return 0;
		}
		ona_kyori = 0;
	}

	cout << "NO" << endl;

	return 0;
}
/*
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

//���z�Ɩ����x�̍\����
struct SHUPI {
	int kane;
	int hara;
};
SHUPI shupi[3];

//�����̎��̋�
int answer = 100000000;

void func(int &hara, int &kane, int day, int n);

int main()
{
	int N, H;      //���؂�����ƍŏ��͂ǂ̂��炢������
	int A, B;      //���ʂɐH�ׂĂǂ̂��炢�����ɂȂ邩
	int C, D;      //���f�ɐH�ׂĂǂ̂��炢�����ɂȂ邩
	int E;         //�f�H�B�ǂ̂��炢�������邩�B

	cin >> N >> H >> A >> B >> C >> D >> E;

	shupi[2].kane = A;
	shupi[2].hara = B;

	shupi[1].kane = C;
	shupi[1].hara = D;

	shupi[0].kane = 0;
	shupi[0].hara = -E;


	int kane = 0;
	int hara = H;

	func(kane, hara, N, 1);

	cout << answer << endl;

	return 0;
}

void func(int &kane, int &hara, int n, int day)
{
	if (n >= day) {
		for (int a = 2; a >= 0; a--) {
			hara += shupi[a].hara;
			kane += shupi[a].kane;
			if (hara <= 0) {
				hara -= shupi[a].hara;
				kane -= shupi[a].kane;
			}
			else {
				func(kane, hara, n, day + 1);
				hara -= shupi[a].hara;
				kane -= shupi[a].kane;
			}
		}
	}
	else {
		//	cout << kane << endl;

		if (answer > kane) {
			answer = kane;
		}
	}
}*/