#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1000;

//女がいる座標
struct ONA {
	int x;
	int y;
};
ONA *ona;
int main() 
{
	int T;			//移動にかかった時間
	int V;			//移動時の速度(分速)
	int n;			//女の数
	int a1, a2;     //移動前の座標
	int b1, b2;     //移動後の座標
	int x, y;

	cin >> a1 >> a2 >> b1 >> b2 >> T >> V >> n;

	//女の座標を格納するための配列を確保
	ona = new ONA[n];

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		ona[i].x = x;
		ona[i].y = y;
	}

	//移動可能な距離
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

//金額と満腹度の構造体
struct SHUPI {
	int kane;
	int hara;
};
SHUPI shupi[3];

//答えの時の金
int answer = 100000000;

void func(int &hara, int &kane, int day, int n);

int main()
{
	int N, H;      //乗り切る日数と最初はどのぐらい満腹か
	int A, B;      //普通に食べてどのぐらい満腹になるか
	int C, D;      //質素に食べてどのぐらい満腹になるか
	int E;         //断食。どのぐらい腹が減るか。

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