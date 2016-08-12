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

const int N = 10000000;
const int D = 1e4;
const int K = 100;

struct MAP {
	int a;
	int b;
	int day;
};
MAP Map[N];
MAP segen[D];

int main()
{
	int n, d, k;

	cin >> n >> d >> k;

	for (int i = 0; i < d; i++) {
		cin >> segen[i].a >> segen[i].b;
	}

	for (int i = 0; i < k; i++) {
		cin >> Map[i].a >> Map[i].b;
	}


	for (int i = 0; i < k; i++) {
		for (int j = 0; j < d; j++) {
			if (Map[i].a >= segen[j].a || Map[i].a >= segen[j].b) {
				if (Map[i].a <= segen[j].a || Map[i].a <= segen[j].b) {
					if (Map[i].b >= segen[j].a && Map[i].b <= segen[j].b) {
						Map[i].day = j + 1;
						break;
					}
					else {
						//ƒS[ƒ‹‚É‹ß‚¢‚Ù‚¤‚Éi‚ÞB
						int a = (int)abs(Map[i].b - segen[j].a);
						int b = (int)abs(Map[i].b - segen[j].b);
						if (a < b) {
							Map[i].a = segen[j].a;
						}
						else {
							Map[i].a = segen[j].b;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << Map[i].day << endl;
	}

	return 0;
}