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

const int M = 9;

int Hyo[M + 1][M + 1];

struct KUKU {
	int x[M];
	int y[M];
	int sp;
	int ep;
};

KUKU kuku[M * M + 1];

int main()
{
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			Hyo[i][j] = i * j;
			int soezi = Hyo[i][j];
			kuku[soezi].y[kuku[soezi].ep] = i;
			kuku[soezi].x[kuku[soezi].ep] = j;
			kuku[soezi].ep++;
			sum += i * j;
		}
	}

	int sa = sum - N;

	while (kuku[sa].sp < kuku[sa].ep) {
		cout << kuku[sa].y[kuku[sa].sp] << " x " << kuku[sa].x[kuku[sa].sp] << endl;
		kuku[sa].sp++;
	}
	
	return 0;
}