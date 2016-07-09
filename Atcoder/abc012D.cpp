#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300;
const int M = 44850;

bool Basu[N + 1][N + 1];     //点から点までの隣接行列
int Time[N + 1][N + 1];      //点から点までの重みを格納する
int Basute[N + 1][N + 1];    //それぞれの点の最大値を格納する
int Basute2[N + 1];          //バス停のその時点での値を格納する
bool Visit[N + 1][N + 1];    //訪れたかどうかのフラグ

//待ち行列
int Q[N + 1];
int sp, ep;

int main()
{
	int n, m;
	cin >> n >> m;
	//バス停a,bとaからbまでにかかる時間
	for (int i = 0; i < m; i++) {
		int a, b, time;
		cin >> a >> b >> time;
		Time[a][b] = time;
		Time[b][a] = time;
		Basu[a][b] = true;
		Basu[b][a] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Basute[i][j] = 1000000;
		}
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				if (Basu[b][c] && !Visit[b][c]) {
					if (Basute[a][c] > Time[b][c] + Basute2[b]) {
						Basute[a][c] = Time[b][c] + Basute2[b];
					}
					Q[ep++] = c;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Basute[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300;
const int M = 44850;

bool Basu[N + 1][N + 1];     //点から点までの隣接行列
int Time[N + 1][N + 1];      //点から点までの重みを格納する
int Basute[N + 1][N + 1];    //それぞれの点の最大値を格納する
int Basute2[N + 1];          //バス停のその時点での値を格納する
bool Visit[N + 1][N + 1];    //訪れたかどうかのフラグ

int main()
{
	int n, m;
	cin >> n >> m;
	//バス停a,bとaからbまでにかかる時間
	for (int i = 0; i < m; i++) {
		int a, b, time;
		cin >> a >> b >> time;
		Time[a][b] = time;
		Time[b][a] = time;
		Basu[a][b] = true;
		Basu[b][a] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Basute[i][j] = 1000000;
		}
	}

	for (int b = 1; b < n; b++) {
		for (int c = b; c <= n; c++) {
			for (int d = 1; d <= n; d++) {
				if (Basu[c][d] == true && !Visit[c][d]) {
					if (Basute[b][d] > Time[c][d] + Basute2[c]) {
						Basute[b][d] = Time[c][d] + Basute2[c];
						Basute2[d] = Basute[b][d];
					}
					Visit[c][d] = true;
					Visit[d][c] = true;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Visit[i][j] = false;
			}
		}

		for (int j = 1; j <= n; j++) {
			Basute2[j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Basute[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
/*#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 300;
const int M = 44850;

bool Basu[N + 1][N + 1];     //点から点までの隣接行列
int Time[N + 1][N + 1];      //点から点までの重みを格納する
int Basute[N + 1][N + 1];    //それぞれの点の最大値を格納する
int Basute2[N + 1];          //バス停のその時点での値を格納する
bool Visit[N + 1][N + 1];    //訪れたかどうかのフラグ

void func(int n, int x, int count, int eki);
int main()
{
int n, m;
cin >> n >> m;
//バス停a,bとaからbまでにかかる時間
for (int i = 0; i < m; i++) {
int a, b, time;
cin >> a >> b >> time;
Time[a][b] = time;
Time[b][a] = time;
Basu[a][b] = true;
Basu[b][a] = true;
}

for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
Basute[i][j] = 1000000;
}
}


for (int z = 1; z <= n; z++) {
Basute[z][z] = 0;

for (int i = 1; i <= n; i++) {
if (Basu[z][i] && !Visit[z][i]) {
Basute[z][i] = Time[z][i];
Basute2[i] = Time[z][i];
Visit[z][i] = true;
Visit[i][z] = true;
}
}
for (int a = 1; a <= n; a++) {
for (int b = 1; b <= n; b++) {
if (Basu[a][b] && !Visit[a][b]) {
if (Basute[z][b] > Time[a][b] + Basute2[a]) {
Basute[z][b] = Time[a][b] + Basute2[a];
Basute2[b] = Basute[z][b];
Visit[a][b] = true;
}
}
}
}

for (int i = 1; i <= n; i++) {
Basute2[i] = 0;
}

for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
Visit[i][j] = false;
}
}
}

for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
cout << Basute[i][j] << " ";
}
cout << endl;
}

return 0;
}*/