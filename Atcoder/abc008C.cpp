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
	int value;    //コインの番号
	bool ura;   //表か裏かfalseが表でtrueは裏
	bool erabu;   //既に選んだかどうか
};
COIN coin[N];     //コインの番号を入れる配列
int  comb[N];     //コインの添え字を保存する
				  
//期待値計算のための分子と分母
double bunbo, bunshi;    

void func(int n, int i);
void func2(int n, double count);
bool tasikame(int n);

int main()
{
	int n;       //コインの枚数
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> coin[i].value;
	}

	func(n, 0);
	printf("%lf\n", bunshi / bunbo);

	return 0;
}

//選ばれてないコインがあるかどうか判別
bool tasikame(int n)
{
	for (int i = 0; i < n; i++) {
		if (coin[i].erabu == false) {
			return false;
		}
	}

	return true;
}

//それぞれの組み合わせを列挙する
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

//列挙された組み合わせを処理する
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

	//表が出た回数を計算
	for (int i = 0; i < n; i++) {
		if (coin[i].ura == false) {
			bunshi++;
		}
	}

	for (int i = 0; i < n; i++) {
		coin[i].ura = false;
	}
}