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

const int N = 100000;
const int M = 2;

int arr[N];
int value[N][M + 1];  //���̐�Βl���L������z��
int ans[N];           //�ŏ��l���L������z��

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	//���ꂼ��̍��̐�Βl�����߂�
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j <= M; j++) {
			value[i][j] = abs(arr[i + j] - arr[i]);
		}
	}
	value[n - 2][1] = abs(arr[n - 1] - arr[n - 2]);

	for (int i = 1; i < n; i++) {
		ans[i] = 1000000000;
	}

	//�_�C�N�X�g���@�ŋ��߂�
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j <= M; j++) {
			if (ans[i] + value[i][j] < ans[i + j]) {
				ans[i + j] = ans[i] + value[i][j];
			}
		}
	}

	if (ans[n - 2] + value[n - 2][1] < ans[n - 1]) {
		ans[n - 1] = ans[n - 2] + value[n - 2][1];
	}

	cout << ans[n - 1] << endl;

	return 0;
}