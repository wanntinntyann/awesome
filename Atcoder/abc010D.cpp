/*#include <iostream>
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
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100;

bool MAP[N + 1][N + 1];   //友達関係を表す隣接行列
int M;					  //SNSの利用者
int G;					  //マークしている女の数
int E;					  //SNSの利用者の人間関係
int *mark;				  //マークしている人間のIDを保存する
bool visit[N];            //確認するための配列
int  miti[N];             //道の本数

int fre(int n, int i, int x, int y, int &count);

int main()
{
	cin >> M >> G >> E;

	mark = new int[M];

	for (int i = 0; i < G; i++) {
		cin >> mark[i];
	}

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		MAP[a][b] = true;
		MAP[b][a] = true;
	}

	int count = 0;
	int temp = fre(M, 0, 0, 0, count);

	cout << count << endl;

	return 0;
}

int fre(int n, int i, int x, int y, int &count)
{
	if (n > i) {
		int num = 0;
		for (int j = x + 1; j < n; j++) {
			if (MAP[y][j] == true) {
				int kazu = 0;
				for (int k = 0; k < G; k++) {
					if (mark[k] == j && !visit[j]) {
						visit[j] = true;
						visit[y] = true;
						kazu++;
					}
				}
				if (kazu > 0) {
					cout << kazu << endl;
					return kazu;
				}
				miti[y]++;
				num += fre(n, i + 1, x, y, count);
				if (num > 0) {
					count++;
				}
				if (miti[y] < count) {
					count = miti[y];
				}
			}
		}
	}

	return 0;
}