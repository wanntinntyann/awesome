#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300;
const int M = 44850;

int Top[N + 1] = { 0 };      //頂点を格納
bool Basu[N + 1][N + 1];     //点から点までの隣接行列
int Time[N + 1][N + 1];      //点から点までの重みを格納する
int Basute[N + 1][N + 1];    //それぞれの点の最大値を格納する
int Basute2[N + 1];          //バス停のその時点での値を格納する
bool Visit[N + 1][N + 1];    //訪れたかどうかのフラグ
bool Visit2[N + 1];
							 
//待ち行列
int Q[2000];
int sp, ep;

int main()
{
	int n, m;
	cin >> n >> m;
	//バス停a,bとaからbまでにかかる時間
	int t = 1;
	for (int i = 1; i <= m; i++) {
		int a, b, time;
		cin >> a >> b >> time;
		Time[a][b] = time;
		Time[b][a] = time;

		if (!Visit2[a] && !Visit2[b]) {
			Top[t++] = a;
			Top[t++] = b;
			Visit2[a] = true;
			Visit2[b] = true;
		}
		else if(!Visit2[a]){
			Top[t++] = a;
			Visit2[a] = true;
		}
		else if (!Visit2[b]) {
			Top[t++] = b;
			Visit2[b] = true;
		}

		Basu[a][b] = true;
		Basu[b][a] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Basute[i][j] = 1000000;
		}
	}

	for (int z = 1; z <= n; z++) {
		Basute[Top[z]][Top[z]] = 0;
		Q[0] = Top[z];
		ep = 1;
		while (sp != ep) {
			int pt = Q[sp++];
			for (int a = 1; a <= n; a++) {
				if (Basu[pt][a] && !Visit[pt][a]) {
					if (Basute[z][a] > Time[pt][a] + Basute2[pt]) {
						Basute[z][a] = Time[pt][a] + Basute2[pt];
						Basute2[a] = Basute[z][a];
					}
					Visit[pt][a] = true;
					Q[ep++] = a;
				}
			}
		}

		ep = 0;
		sp = 0;
		for (int i = 1; i <= n; i++) {
			Basute2[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Visit[i][j] = false;
			}
		}
	}

	int min = 1000000;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 1; j <= n; j++) {
			if (max < Basute[i][j]) {
				max = Basute[i][j];
			}
		}
		if (min > max) {
			min = max;
		}
	}

	cout << min << endl;
	return 0;
}