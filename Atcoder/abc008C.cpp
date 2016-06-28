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

const int N = 100;

struct COIN {
	int value;    //�R�C���̔ԍ�
	bool ura;   //�\������false���\��true�͗�
	bool erabu;   //���ɑI�񂾂��ǂ���
};
COIN coin[N];     //�R�C���̔ԍ�������z��
int  comb[N];     //�R�C���̓Y������ۑ�����
				  
//���Ғl�v�Z�̂��߂̕��q�ƕ���
double bunbo, bunshi;    

void func(int n, int i);
void func2(int n, double count);
bool tasikame(int n);

int main()
{
	int n;       //�R�C���̖���
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> coin[i].value;
	}

	func(n, 0);
	printf("%lf\n", bunshi / bunbo);

	return 0;
}

//�I�΂�ĂȂ��R�C�������邩�ǂ�������
bool tasikame(int n)
{
	for (int i = 0; i < n; i++) {
		if (coin[i].erabu == false) {
			return false;
		}
	}

	return true;
}

//���ꂼ��̑g�ݍ��킹��񋓂���
void func(int n, int i)
{
	if (i >= n) {
		for (int a = 0; a < n; a++) {
			coin[comb[a]].erabu = true;
		}
		if (tasikame(n)) {
			bunbo++;
			func2(n, bunbo);
		}
		for (int a = 0; a < n; a++) {
			coin[comb[a]].erabu = false;
		}
	} else{
		for (int a = 0; a < n; a++) {
			comb[i] = a;
			func(n, i + 1);
		}
	}
}

//�񋓂��ꂽ�g�ݍ��킹����������
void func2(int n, double count)
{
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			if (coin[comb[b]].value % coin[comb[a]].value == 0) {
				if (coin[comb[b]].ura == true) {
					coin[comb[b]].ura = false;
				}
				else {
					coin[comb[b]].ura = true;
				}
			}
		}
	}

	//�\���o���񐔂��v�Z
	for (int i = 0; i < n; i++) {
		if (coin[i].ura == false) {
			bunshi++;
		}
	}

	for (int i = 0; i < n; i++) {
		coin[i].ura = false;
	}
}