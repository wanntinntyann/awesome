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


const int N = 10000;

int arr[N];

bool func(string str, int *arr, int k);

int main()
{
	string str;
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	str = to_string(n);

	while(func(str, arr, k)){
		n++;
		str = to_string(n);
	}

	cout << str << endl;
	return 0;
}

bool func(string str, int *arr, int k)
{
	for (int i = 0; i < k; i++) {
		if (str.find(to_string(arr[i])) != -1) {
			return true;
		}
	}

	return false;
}