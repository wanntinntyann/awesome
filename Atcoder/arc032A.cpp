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
#include <ctime>
#include <fstream>
using namespace std;


const int N = 100;
const int M = 200;

int arr[N + 1];
int cost[M + 1];

int main()
{
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = -100; i <= 100; i++) {
		for (int j = 1; j <= n; j++) {
			sum += pow(arr[j] - i, 2);
		}
		cost[i + 100] = sum;
		sum = 0;
	}

	sort(cost, cost + M + 1);

	cout << cost[0] << endl;


	return 0;
}